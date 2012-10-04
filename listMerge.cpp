#include <iostream>

using namespace std;

typedef struct node node;

typedef struct node{
	int data;
	node *next;
}*pnode;

void create(pnode head, int *a, int n){
	head->data = a[0];
	pnode p = head;
	head->next = NULL;
	int i = 1;
	for(; i<n; i++){
		pnode tmp = new node;
		tmp->data = a[i];
		tmp->next = NULL;
		p->next = tmp;
		p = tmp;
	}

}

std::ostream & operator<<( std::ostream &os, pnode head){
	while(NULL != head){
		os << head->data << " ";
		head = head->next;
	}
	return os;
}

pnode listMerge(pnode h1, pnode h2){
	pnode head = NULL;
	pnode ptmp = NULL;

	while(NULL != h1 && NULL != h2){
		if(h1->data < h2->data){
			ptmp = h1->next;
			h1->next = head;
			head = h1;
			h1 = ptmp;
		}else{
			ptmp = h2->next;
			h2->next = head;
			head = h2;
			h2 = ptmp;
		}
	}
	
	pnode last = NULL;
	if(h1 != NULL)
		last = h1;
	else 
		last = h2;
	while(NULL != last){
		ptmp = last->next;
		last->next = head;
		head = last;
		last = ptmp;
	}
	return head;
}

int main(){
	int a[] = {1,3,5,7,9,11,13,15,17};
	int b[] = {0,2,4,6,8,10,12,14,16,18,19,20,21,22,23};
	node head1;
	node head2;
	create(&head1, a, 9);
	create(&head2, b, 15);
	//std::cout <<&head1 << std::endl;
	pnode newhead = listMerge(&head1, &head2);
	cout << newhead << endl;
	return 0;
}
