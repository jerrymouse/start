#include <iostream>
#include <memory>
#include <tr1/memory>
#include <vector>
using namespace std;

class Base{
	public:
		string b;
		Base(){cout << "B" << endl;}
		virtual ~Base(){cout << "~Base" << endl;}
};

class Derived : public Base{
	public :
		string d;
		Derived(){cout << "D" << endl;}
		~Derived(){cout << "~Derived" << endl;}
};

int main(){
//	自动析构	
//	Base b;
//	Derived d;

//	new 要手动的 delete	
//	Base *b = new Base();
//	Derived *d = new Derived();

//	std::auto_ptr<Base> pbase(new Base());	
//	auto_ptr<Derived> pd(new Derived());
// 父类指针指向子类，基类析构virtual,智能指针负责调用指针所指向的析构函数
// 其实是delete，注意没有delete[],因此数组不能用智能指针
//	auto_ptr<Base> pb(new Derived());
	
// 编译时要添加 -std=c++0x	
//	tr1::shared_ptr<Base> spb(new Base());
	typedef tr1::shared_ptr<Base> BP;
	vector<BP> v;
	int i=0;
	for(i=0; i<10; i++){
		v.push_back(BP(new Base()));
	}

//默认复制构造函数	
//两个对象 	
//	Base b1;
//	Base b2 = b1;
//	Base b3(b1);
//	cout << (&b1==&b2) << endl;
	return 0;
}
