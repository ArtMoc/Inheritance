#include "Graduate.h"
const string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const string& subject)
{
	this->subject = subject;
}
//                CONSTRUCTORS:
Graduate::Graduate
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, double rating,
	const string& subject
) :Student(last_name, first_name, age, speciality, group, rating)
{
	set_subject(subject);
	cout << "G_Constructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "G_Destructor:\t" << this << endl;
}
void Graduate::print()const
{
	Student::print();
	cout << "Theme of the diploma: " << subject << endl;
}