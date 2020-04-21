#pragma once
#include <exception>
#include <string>

using namespace std;

class myException
{
private:
	string message;
	int codeException;
public:
	myException(string, int);
	string show();
	int getCode();
};