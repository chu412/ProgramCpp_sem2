#include "Exception.h"
#include <exception>
#include <utility>

using namespace std;

myException::myException(string _mes, int _code)
{
	message = move(_mes);
	codeException = _code;
}

string myException::show()
{
	return message;
}

int myException::getCode()
{
	return codeException;
}