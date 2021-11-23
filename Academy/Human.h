#pragma once
#include <iostream>
#include <string>
using namespace std;
class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	unsigned int get_age()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);
	//                 CONSTRUCTORS:
	Human(const string& last_name, const string& first_name, unsigned int age);
	virtual ~Human();
	//                METHODS:
	virtual void print()const;
};
