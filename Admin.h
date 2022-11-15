#ifndef Admin_h
#define Admin_h
#include "User.h"

class Admin : public User {
private:
	const char* password = { "12345" };
public:
	bool login();
	~Admin();
};

#endif