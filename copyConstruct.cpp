#include <iostream>

using namespace std;

class Base{
	public:
		string s;
		Base(string s){
			this->s = s;
			cout << "argument s: " << s << endl;
		}
		Base(){
			cout << "default construct in Base" << endl;
		}
		Base(const Base &b){
			cout << "copy construct in Base" << endl;
		}
		Base& operator=(const string s){
			cout << "operator = s:" << s << endl;
			this->s = s;
			return *this;
		}

		~Base(){
			cout << "~Base" << endl;
		}
	private:
		Base & operator=(const Base &);

};

class Base1{
	public : 
		int i;


	/*	explicit*/ Base1(int i=0){
			this->i = i;
			cout << "init by value: " << i << endl;
		}

		Base1(const Base1 &b){
			cout << "copy construct in base11" << endl;
			this->i = b.i;
		}
		 Base1& operator=(const Base1 b){
			this->i = b.i; 
			cout << "operator =" << endl;
			return *this;
		 }

		~Base1(){cout << "~Base1: " << i << endl;}
};

int main(){
	//Base b1;
	//Base b2 = string("chen");
	//(b2 = string("hui")) = string("haha");
	//cout << b2.s << endl;
	
//	Base1 bb = 1234;
//	cout << bb.i << endl;
//	bb.i = 3456;
//	Base1 cc = bb;
//	cout << cc.i << endl;
	
	Base1 t;
	t = 1;
	t.i = 2;
	return 0;
}
