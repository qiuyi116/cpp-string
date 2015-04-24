#include <iostream>
#include "my_string.h"

int
main()
{
	using namespace std;

	my_string str;

	cout << "Please key in a string: ";
	cin >> str;
	cout << str[0] << endl;

	return 0;
}
