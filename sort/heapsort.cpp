#include <iostream>

using namespace std;
void printA(int*, int);
void swap(int &i, int &j){
	int tmp = i;
	i = j;
	j = tmp;
}

void adjust(int *arr, int i, int n){
	int child = i*2+1;
	while(child<n){
		if(child+1<n && arr[child+1]>arr[child])
			child++;
		if(arr[i]<arr[child])
			swap(arr[i], arr[child]);
		else break;

		i = child;
		child = child*2+1;
	}
}

void heapsort(int *arr, int n){
	int i;
	for(i=n/2-1; i>=0; i--)
		adjust(arr, i, n);
	for(i=0; i<n-1; i++){
		swap(arr[0], arr[n-1-i]);
		adjust(arr, 0, n-1-i);
	}
}

void printA(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]){
	int a[] = {0,8,7,6,5,4,3,2,1};
	heapsort(a, 9);
	return 0;
}
