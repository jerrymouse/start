#include <iostream>

using namespace std;

void swap(int &i, int &j){
	int tmp = i;
	i = j;
	j = tmp;
}

void printA(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void quicksort(int *a, int start, int end){
	if(start >= end) // at least two element
		return;

	int pivot = a[start];
	int l = start, h = end;
	while(l<h){
		while(l<h && a[h]>pivot)
			h--;
		if(l<h)
			swap(a[l++], a[h]);
		while(l<h && a[l]<pivot)
			l++;
		if(l<h)
			swap(a[l], a[h--]);
	}// end of while, l==h
	a[l] = pivot;
	quicksort(a, start, l-1);
	quicksort(a, l+1, end);
}

void quicksort1(int *a, int start, int end){
	if(start >= end)
		return;

	int less = start, key = a[start], cur;
	for(cur=start+1; cur<=end; cur++){
		if(a[cur]<key)
			swap(a[++less], a[cur]);
	}
	swap(a[start], a[less]);
	quicksort1(a, start, less-1);
	quicksort1(a, less+1, end);
}

void quicksort2(int *a, int start, int end){
	if(start >= end)
		return;
	int l = start+1;
	int h = end;
	int key = a[start];

	while(l!=h){
		if(a[l]<=key)
			l++;
		else{
			while(l!=h && a[h]>key)
				h--;
			swap(a[l], a[h]);
		}
	}
	if(a[l]>key)
		l--;
	swap(a[start], a[l]);
	printA(a, 8);
	quicksort2(a, start, l-1);
	quicksort2(a, l+1, end);
}

int main(){
	int a[] = {3,0,2,8,0,9,1,0};
	quicksort2(a, 0, 7);
//	printA(a, 8);
	return 0;
}
