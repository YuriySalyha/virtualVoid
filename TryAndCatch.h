#ifndef TryAndCatch_h
#define TryAndCatch_h

class Exception
{
public:
	const char* message;
	Exception(const char* message);
};
class IsIndexOkey : public Exception {
public:
	IsIndexOkey() : Exception("Could not be more than list"){}
};
class DivideByZeroException : public Exception
{
public:
	DivideByZeroException() : Exception("Could not divide by zero"){}
};
#endif // !TryAndCatch