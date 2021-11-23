#pragma once
#include "Student.h"
class Graduate :public Student
{
	string subject;
public:
	const string& get_subject()const;
	void set_subject(const string& subject);
	//                CONSTRUCTORS:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& subject
	);
	~Graduate();
	void print()const;
};

