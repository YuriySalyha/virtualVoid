#include "Admin.h"
#include <iostream>
#include <string>

bool Admin::login() {
	std::string adminPassword;

	std::cout << "Enter admin password: ";
	std::cin >> adminPassword;
	return !std::strcmp(password, adminPassword.c_str());
}

Admin::~Admin() {
	delete password;
}