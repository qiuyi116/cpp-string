#ifndef MY_STRING
#define MY_STRING

#include <iostream>

using namespace std;

class my_string {
public:
	//constructors
	my_string(const char *s = NULL);
	my_string(const my_string &str);

	//deconstructor
	~my_string();

	//methods
	size_t size() const;
	const char* data() const;
	void set_length(size_t len);
	//const char* c_str() const;

	//operator overloading
	my_string operator+(const my_string &str) const;
	my_string& operator=(const my_string &str);
	my_string& operator+=(const my_string &str);
	bool operator==(const my_string &str) const;
	char& operator[](int n) const;

	friend istream& operator>>(istream &is, my_string &str);
	friend ostream& operator<<(ostream &os, my_string &str);

private:
	char*	_data;
	size_t	length;
};

#endif
