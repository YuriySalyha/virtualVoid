#pragma warning (disable:4996)
#include "Moderator.h"
#include <string>
#include <iostream>
bool Moderator::login() {
	std::string moderatorPassword;

	std::cout << "Enter moderator password: ";
	std::cin >> moderatorPassword;

	return !std::strcmp(password, moderatorPassword.c_str());
}

void Moderator::changePassword() {
	std::string moderatorPassword;
	std::cout << "Enter new moderator password";
	std::cin >> moderatorPassword;
	std::strcpy(password, moderatorPassword.c_str());
}

Moderator::~Moderator() {
	delete password;
}