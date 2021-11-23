#include "Teacher.h"
const string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}

//                  CONSTRUCTORS:
Teacher::Teacher
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, unsigned int experience
) :Human(last_name, first_name, age)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "T_Constructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "T_Destructor:\t" << this << endl;
}
void Teacher::print()const
{
	Human::print();
	cout << "Speciality: " << speciality << ", Experience: " << experience << " age" << endl;
}