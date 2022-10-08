#ifndef User_h
#define User_h

class User {
public:
	virtual bool login() = 0;
	virtual void changePassword() {}
	virtual ~User() {}
};

#endif // !User_h