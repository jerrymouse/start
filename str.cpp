/*
 * split the str into minimal spieces of palindrome 
 * aababa : a, ababa; not aa, bab, a
 *
 * */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void printA(vector<vector<int> > &vv){
	int i, j;
	for(i=0; i<vv.size(); i++){
		for(j=0; j<vv[i].size(); j++)
			cout << vv[i][j] << " " ;
		cout << endl;
	}
}

bool isr(const char *start, const char* end){
	while(start <= end){
		if(*start != *end)
			return false;
		++start;
		--end;
	}
		
	return true;
}

int minsplit(const char *str){
	int len = strlen(str);
	int i, j, k;
	std::vector<std::vector<int> > vv(len, std::vector<int>(len, 0));


	for(i=0; i<len; i++){
		vv[i][i] = 1;
	}

	for(i=1; i<len; i++){ // step length
		for(j=0; j+i<len; j++){ //[j,j+i]
			if(isr(str+j, str+j+i))
				vv[j][j+i] = 1;
			else{
				int min = len;
				for(k=j; k<j+i; k++){ // k split [j, j+i] into [j, k] and [k+1, j+i]
					int tmp = vv[j][k]+vv[k+1][j+i]; 
					if ( tmp < min )
						min = tmp;
				}
				vv[j][j+i] = min;
			}
			
		}
	}
	printA(vv);
	return vv[0][len-1];
}

int main(){
	char str[100];

	while(true){
		cout << "input string: ";
		cin >> str;
		int c = minsplit(str);
		cout << c << endl;
	}

	return 0;
}
