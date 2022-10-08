#include "User.h"

class Admin : public User {
private:
	const char* password = { "12345" };
public:
	bool login();
	~Admin();
};