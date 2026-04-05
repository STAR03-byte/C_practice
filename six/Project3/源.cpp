#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	string m_PName;

	Phone(string pName) {
		m_PName = pName;
	}
};

class Person
{
public:
	string m_Name;
	Phone m_PName;

	Person(string name,string pName) :m_Name(name), m_PName(pName) {

	}
};

void test01(){
	Person p("ÕÅÈý","Æ»¹û");

}

int main() {
	test01();
	return 0;
}