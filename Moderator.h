#include "User.h"

class Moderator : public User{
private:
	char* password = new char[3]{ '1', '2', '3'};
public:
	bool login();
	void changePassword();
	~Moderator();
};