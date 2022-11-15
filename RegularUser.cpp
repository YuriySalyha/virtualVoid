#include "RegularUser.h"
#include <string>
#include <iostream>

using namespace std;

RegularUser* RegularUser::registration() {
	RegularUser* output = {};
	cout << "Enter the username: ";
	cin >> output->username;
	cout << "Enter the name: ";
	cin >> output->name;
	cout << "Enter the surname: ";
	cin >> output->surname;	
	cout << "Enter the surname: ";
	cin >> output->password;	
	cout << "Enter the surname: ";
	cin >> output->phone;
	return output;
}


RegularUser* RegularUser::passwordChange() {
	RegularUser* a = {};
	return a;
}

bool RegularUser::login() {
	std::string userName;
	std::cout << "Enter username: ";
	std::cin >> userName;
	std::string userPassword;
	std::cout << "Enter user password: ";
	std::cin >> userPassword;

	return login(userName.c_str(), userPassword.c_str());

}


bool RegularUser::login(const char* username, const char* password) {
	return !std::strcmp(this->username, username) &&
		!std::strcmp(this->password, password);
}

RegularUser::~RegularUser() {
	if (username != nullptr) {
		delete username;
	}
	delete password;

}