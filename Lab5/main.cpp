#include "Min.h"
#include "Exception.h"
#include "Array.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
	cout << "============Min-element==============" << endl;
	int a, b;
	cout << "Enter two number a and b:" << endl;
	cin >> a >> b;
	cout << "Smaller number is " << Min(a, b) << endl;
	cout << "=====================================" << endl;
	int n;
	cout << "===============Array=================" << endl;
	cout << "Enter size of array:" << endl;
	cin >> n;
	Array<int> arr(n);
	cout << "Enter n value to fill array:" << endl;
	arr.inArray();
	int ind;
	cout << "Enter an index to show the element:" << endl;
	cin >> ind;
	try
	{
		cout << arr[ind] << endl;
	}
	catch (myException& exc)
	{
		cout << "Message: " << exc.show() << endl;
		cout << "Error Code: " << exc.getCode() << endl;
		exit(1);
	}
	return 0;
}