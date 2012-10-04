#include <iostream>
#include <fstream>

using namespace std;

class FileOpt{
	public :
		ifstream f;
		FileOpt(){}
		FileOpt(const char *fname):f(fname){}
		void read(){
			string s;
			f >> s;
			cout << s;
		}

		FileOpt(const FileOpt &fopt){
		}
};

int main(){
	FileOpt test1("test");
//	FileOpt test2(test1);
	
//	test1.read();
	return 0;
}
