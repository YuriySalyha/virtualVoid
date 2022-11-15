#include "Shop.h"
#include "Admin.h"
#include "Moderator.h"
#include<iostream>
#include "RegularUser.h"
Shop::Shop() {
	users.push_back(new Admin);
	users.push_back(new Moderator);
}

void Shop::registration() {
	RegularUser a;
	users.push_back(a.registration());
}

void Shop::changePassword(int index) {
	std::cout << "Enter new password: ";
	
	//users[index].
}

void Shop::login() {
	int userType;
	std::cout << "Chose role:\n1- Admin\n2 - Moderator\n3 - User\n:";
	std::cin >> userType;
	switch (userType) {
	case 1:
	case 2:
		while (!users[userType - 1]->login()) {
			std::cout << "Incorrect password. Please, try again\n";
		}
		loggedUser = users[userType - 1];
		break;
	case 3:
		bool isFound = false;
		while (!isFound) {
			std::string userName;
			std::cout << "Enter username: ";
			std::cin >> userName;
			std::string userPassword;
			std::cout << "Enter user password: ";
			std::cin >> userPassword;
			for (int i = 2; i < users.size(); i++) {
				RegularUser* user = dynamic_cast<RegularUser*>(users[i]);
				isFound = user->login(userName.c_str(), userPassword.c_str());
				if (isFound) {
					loggedUser = users[i];
					break;
				}
			}
		}
		break;
	}
}
