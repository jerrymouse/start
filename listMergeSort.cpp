#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};
typedef struct node node;

node* merge(node *p, node *q){
	if( NULL == p )
		return q;
	if( NULL == q )
		return p;

	node *head = NULL;
	node *tail = NULL;
	while( p != NULL && q != NULL ){
		node *temp = NULL;
		if( p->data < q->data){
			temp = p;
			p = p->next;
		}else{
			temp = q;
			q = q->next;
		}
		temp->next = NULL;
		if( head == NULL ){
			head = temp;
			tail = temp;
		}else{
			tail->next = temp;
			tail = temp;
		}
	}
	
	if( p != NULL ){
		tail->next = p;
	}
	if( q!= NULL ){
		tail->next = q;
	}
	return head;
}

node* mergeSort(node *head){
	if( NULL == head ){
		return NULL;
	}

	node *arr[64] = {0};
	node *cur = head;

	while( cur != NULL ){
		node *tmp = cur;
		cur = cur->next;
		tmp->next = NULL;

		int i = 0;
		while(i < 64){
			if(arr[i] != NULL){
				tmp = merge(arr[i], tmp);
				arr[i] = NULL;
				i++;
			}else{
				arr[i] = tmp;
				break;
			}
		}
	}

	node *result = arr[0];
	int i;
	for( i = 1; i < 64; i++ ){
		result = merge(result, arr[i]);
	}
	return result;
}

node* create(int *arr, int n){
	node *head = NULL;
	node *tail = NULL;
	int i;
	
	for( i = 0; i < n; i++ ){
		node *tmp = new node;
		tmp->data = arr[i];
		tmp->next = NULL;

		if( NULL == head ){
			head = tmp;
			tail = tmp;
		}else{
			tail->next = tmp;
			tail = tmp;
		}
	}
	return head;
}

void printL(node *head){
	node *cur = head;
	while( cur != NULL ){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	int a[] = {1,3,9,8,0,6,7,5,4,2,123,-1};
	node *head = create(a, 12);
	head = mergeSort(head);
	printL(head);
	return 0;
}
