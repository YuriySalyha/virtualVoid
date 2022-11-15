#ifndef RegularUser_h
#define RegularUser_h
#include "User.h"

class RegularUser : public User
{
private:
	char* username;
	char* password;
	char* name;
	char* surname;
	char* phone;
public:
	bool login();
	bool login(const char* username, const char* password);
	static RegularUser* registration();
	~RegularUser();
	RegularUser* passwordChange();
};
#endif