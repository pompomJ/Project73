#include <iostream>
#include <string.h>

class Person {
public:
	Person() {
		name = NULL;
	}
	Person(const char *str) {
		int len = (int)strlen(str); //ƒƒ‚ƒŠ‚ğ“®“I‚ÉŠm•Û
		name = new char[len + 1];
		strcpy(name, str);
	}
	~Person() {
		delete[] name; //ƒƒ‚ƒŠ‚ğ‰ğ•ú
	}
	Person & operator=(const Person & psn);
	char* GetName() {
		return name;
	}
private:
	char *name;
};

Person & Person::operator=(const Person & psn)
{
	if (this == &psn) return *this;

	delete[] name;
	int len = (int)strlen(psn.name);
	name = new char[len + 1];
	strcpy(name, psn.name);
	return *this; 
}

using namespace std;
int main()
{
	Person psn1("Mika"), psn2("Richard");
	psn1 = psn2;
	cout << psn1.GetName() << endl;
}