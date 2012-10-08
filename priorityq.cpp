#include <iostream>

using namespace std;

typedef struct node{
	int priority;
	int data;
	struct node *next;
}node, *pnode;

void printL(pnode);
bool insert(pnode *head, pnode value){
	pnode prev = NULL;
	pnode cur = *head;

	while(cur != NULL){	// queue is not NULL
		if(cur->priority == value->priority){
			return false;
		}else if(cur->priority < value->priority){
			if(NULL == prev){	// 1.before head
				value->next = cur;
				*head = value;
			}else{				// 2.insert between
				value->next = prev->next;
				prev->next = value;
			}
			return true;
		}
		prev = cur;
		cur = cur->next;
	}

	if(NULL != prev){			// 3.the tail
		value->next = prev->next;
		prev->next = value;
	}else{				// queue is null
		*head = value;
		value->next = NULL;
	}
	return true;
}

void delete_(pnode *head, pnode v){
	pnode cur = *head;
	pnode prev = NULL;
	while(cur != NULL){
		if(cur == v){
			if(NULL == prev){
				*head = cur->next;
			}else{
				prev->next = cur->next;
			}
			free(cur);
		}
		prev = cur; 
		cur = cur->next;
	}
}


void create(pnode *head, int *val, int *prior, int n){
	int i;
	for(i=0; i<n; i++){
		pnode p = new node;
		p->data  = val[i];
		p->priority = prior[i];
		p->next = NULL;
		insert(head, p);
	}
}

void printL(pnode head){
	while(NULL != head){
		cout << "data: " << head->data << " " << "prior: " << head->priority<< endl;
		head = head->next;
	}
}

int main(){
	int val[] = {1,2,3,4,5,6,7,8,9};
	int prior[] = {9,8,7,6,5,4,3,2,1};
	pnode head = NULL;
	create(&head, val, prior, 9);
	printL(head);
	return 0;
}
