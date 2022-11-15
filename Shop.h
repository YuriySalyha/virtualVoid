#ifndef Shop_h
#define Shop_h
#include <vector>
#include "User.h"
class Shop
{
private:
	std::vector<User*> users;

public:
	User* loggedUser;
	Shop();
	void login();
	void registration();
	void changePassword(int index);
};
#endif
