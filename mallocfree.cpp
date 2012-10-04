#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
using namespace std;

#define K1 1024
#define K32 (K1*32)
#define K2 (K1*2)

#define PTR_S (sizeof(void*))
typedef struct item{
	uint16_t size;
	union{
		char mem[PTR_S];
		struct item *next;
	}un;
}__attribute__ ((packed)) item;
#define ITEM_SIZE (sizeof(item)-PTR_S)

static void *memory = NULL;
static item *freelist = NULL;


bool init(uint16_t size){
	memory = malloc(size*sizeof(char));
	if(!memory)
		return false;
	freelist = (item*)memory;
	freelist->size = size-ITEM_SIZE;
	freelist->un.next = NULL;
	return true;
}

void cut(item *cur, uint16_t size){
	if(cur->size-size < (uint16_t)ITEM_SIZE)
		return;

	item *next = (item*)((char*)cur + sizeof(uint16_t) + size);
	next->size = cur->size - size - ITEM_SIZE;
	next->un.next = cur->un.next;
	cur->un.next = next;
	cur->size = size;
}

void* malloc_(uint16_t size){
	if(size < 4)		// 4 indicates the size of pointer, should be PTR_S.
		size = 4;
	item *cur = freelist;
	item *prev = NULL;
	while(NULL != cur){
		if(cur->size >= size){
			cut(cur, size);
			if(NULL == prev){
				freelist = cur->un.next;
			}else{
				prev->un.next = cur->un.next;
			}
			return (char*)cur + ITEM_SIZE;
		}
		prev = cur;
		cur = cur->un.next;
	}
	return NULL;
}

void merge(item* prev, item *next){
	if(NULL == prev || NULL == next)
		return;

	if((char*)prev + ITEM_SIZE + prev->size != (char*)next)
		return;

	prev->size = prev->size + next->size + ITEM_SIZE;
	prev->un.next = next->un.next;
}

void free_(void *p){
	if(NULL == p)
		return;

	item* insert = (item*)((char*)p - ITEM_SIZE);
	item* cur = freelist;
	item* prev = NULL;
	
	while(NULL != cur){ 
		if(cur > insert){  // the sequence in memory is (prev, insert ,cur)
			if(NULL == prev){
				insert->un.next = freelist;
				freelist = insert;
			}else{
				insert->un.next = prev->un.next;
				prev->un.next = insert;
			}
			merge(insert, insert->un.next); // the merge sequence should be (insert, cur) and then (prev, insert)
			merge(prev, insert);
			return;
		}
		prev = cur;
		cur = cur->un.next;
	}
	
	if(NULL == prev){
		freelist = insert;
	}else{
		prev->un.next = insert;
	}
	insert->un.next = NULL;
	merge(prev, insert);
}

int main(){
	init(K2);
/*malloc all*/
	const int count = 100000;
	void *p[count];
	int len = 0, i;
	item *tmp = freelist;

	while(freelist != NULL)
		p[len++] = malloc_(14);
	assert(freelist == NULL);
	for(i=0; i<len; i++){
		free_(p[i]);
	}
	assert(freelist->size == K2-ITEM_SIZE);
	assert(freelist->un.next == NULL);
	assert(freelist == tmp);

	len = 0;
	i = 1;
	while(freelist != NULL){
		p[len++] = malloc_(i%30);
		i++;
		if(freelist->un.next == NULL && freelist->size < 4)
			break;
	}
	cout << "last size: " << freelist->size << endl;
	for(i=0; i<len; i++){
		free_(p[i]);
	}
	assert(freelist->size == K2-ITEM_SIZE);
	assert(freelist->un.next == NULL);
/* malloc one */
//	void *tmp = freelist;
//	void *q = malloc_(14);
//	free_(q);
//	assert(tmp == freelist);

	return 0;
}
