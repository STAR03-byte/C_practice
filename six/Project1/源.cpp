#include<iostream>
//#include<string>
using namespace std;

class Student {
public: //公共权限
	//属性
	string sname;//姓名
	int sno;//学号

	//行为
	
	void showStudent() {
		cout << sname << " " << sno << endl;
	}
};

int main() {
	//实例化
	Student s1;
	s1.sname = "张三";
	s1.sno = 123456;
	
	s1.showStudent();

	return 0;
}