//The basic_string implement by QY.#include <cstring>
#include <cstring>
#include <cstdlib>
#include "my_string.h"


my_string::my_string(const char *s) //OK
{
	if (!s) {
		length = 0;
		_data = new char[1];
		*_data = '\0';
	}
	else {
		length = strlen(s);
		_data = new char[length+1];
		strcpy(_data, s);
	}

}

my_string::my_string(const my_string &str) //OK
{
	length = str.size();
	_data = new char[length+1];
	strcpy(_data, str.data());
}

my_string::~my_string() //OK
{
	delete [] _data;
	length = 0;
}

size_t
my_string::size() const //OK
{
	return length;
}

const char*
my_string::data() const //OK
{
	return _data;
}

void
my_string::set_length(size_t len) //OK
{
	length = len;
}

my_string
my_string::operator+(const my_string &str) const //OK
{
	size_t new_size = length + str.size();
	char* s = new char[new_size+1];
	strcpy(s, _data);
	strcat(s, str.data());
	my_string new_str(s);
	new_str.set_length(new_size);
	delete [] s;

	return new_str;
}

my_string&
my_string::operator=(const my_string &str) //OK
{
	if (this == &str) //What this is?
		return *this;

	delete [] _data;
	length = str.size();
	_data = new char[length+1];
	strcpy(_data, str.data());

	return *this;
}

my_string&
my_string::operator+=(const my_string &str) //OK
{
	length += str.size();
	char* new_data = new char[length+1];
	strcpy(new_data, _data);
	strcat(new_data, str.data());
	delete [] _data;
	_data = new_data;

	return *this;
}

bool
my_string::operator==(const my_string &str) const //OK
{
	if (strcmp(_data, str.data()) == 0)
		return true;
	else
		return false;
}


char&
my_string::operator[](int n) const // error when it comes to inline
{

	if (n > length)
		exit(0);
	else
		return _data[n];
}


istream&
operator>>(istream &is, my_string &str) // error for string always
{										// end with spaces
	char tem[1000];
	is >> tem;
	str.length = sizeof(tem) -1;
	if (str._data != NULL)
		delete [] str._data;
	else
		delete str._data;
	str._data = new char[str.length + 1];
	strcpy(str._data, tem);
	return is;
}

ostream&
operator<<(ostream &os, my_string &str) //OK
{
	os << str._data;

	return os;
}
