#include <iostream>
#include <string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//                 CONSTRUCTORS:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "H_Constructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "H_Destructor:\t" << this << endl;
	}
	//                METHODS:
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " ���.\n";
	}
};

class Student:public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//                       COUNSTRUCTOR:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	):Human(last_name, first_name, age)//���������� ����������� �������� ������
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "S_Constructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "S_Destructor:\t" << this << endl;
	}

	//                 METHODS:
	void print()const
	{
		Human::print();
		cout << "�������������: " << speciality 
			<< ", ������: " << group
			<< "������������: " << rating << endl;
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}


	//                  CONSTRUCTORS:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "T_Constructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "T_Destructor:\t" << this << endl;
	}	
	void print()const
	{
		Human::print();
		cout << "Speciality: " << speciality << ", Experience: " << experience << " age" << endl;
	}
};

class Graduate :public Student
{
	string subject;
public:
	const string& get_subject()const
	{
		return subject;
	}
	void set_subject(const string& subject)
	{
		this->subject = subject;
	}
	//                CONSTRUCTORS:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_subject(subject);
		cout << "G_Constructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "G_Destructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << "Theme of the diploma: " << subject << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessie", 22, "Methamphitamine manufacturing", "WW_01 ", 93);
	s.print();

	Teacher t("White", "Walter", 50, "Chemistry", 25);
	t.print();

	Graduate g("Schrader", "Hank", 42,
		"Cryminalistic", "OBN", 95,
		"How to catch Heisenberg");
	g.print();
}