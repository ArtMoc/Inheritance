
#include <iostream>
#include <string>
#include <fstream>
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
#ifdef DEBUG
		cout << "H_Constructor:\t" << this << endl;
#endif // DEBUG
	}
	virtual ~Human()
	{
#ifdef DEBUG
		cout << "H_Destructor:\t" << this << endl;
#endif // DEBUG
	}
	//                METHODS:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return os
		<< obj.get_last_name() << " " 
		<< obj.get_first_name() << " "
		<< obj.get_age() << " лет.";
}

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
	):Human(last_name, first_name, age)//Делегируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
#ifdef DEBUG
		cout << "S_Constructor:\t" << this << endl;
#endif // DEBUG
	}
	~Student()
	{
#ifdef DEBUG
		cout << "S_Destructor:\t" << this << endl;
#endif // DEBUG

	}

	//                 METHODS:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality 
			<< ", группа: " << group
			<< "успеваемость: " << rating << endl;
	}
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human)obj;
	return os
		<< " , спец:" << obj.get_speciality()
		<< ", группа:" << obj.get_group()
		<< ", успеваемость:" << obj.get_rating();
}

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
#ifdef DEBUG
		cout << "T_Constructor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "T_Destructor:\t" << this << endl;
#endif // DEBUG

	}	
	void print()const
	{
		Human::print();
		cout << "Speciality: " << speciality << ", Experience: " << experience << " age" << endl;
	}
};

ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human)obj;
	return os
		<< ", спец:" << obj.get_speciality()
		<< ", опыт преподавания: " << obj.get_experience() << " лет.";
}

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
#ifdef DEBUG
		cout << "G_Constructor:\t" << this << endl;
#endif // DEBUG

	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "G_Destructor:\t" << this << endl;
#endif // DEBUG

	}
	void print()const
	{
		Student::print();
		cout << "Theme of the diploma: " << subject << endl;
	}

};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	
	return os << (Student)obj << "Тема: " << obj.get_subject();
}


//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
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
#endif // INHERITANCE


	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),//upcast
		new Student("Vercetti", "Tomas", 30, "Cryminal", "Vice", 90),//upcast
		new Teacher("White", "Walter", 50, "Chemistry", 25),//upcast
		new Student("Diaz", "Ricardo", 55, "Weapons distribution", "Vice", 80),
		new Graduate("Schrader", "Hank", 42,
		"Cryminalistic", "OBN", 95,	"How to catch Heisenberg"),
		new Teacher("Eistein", "Albert", 143, "Astronomy", 120)
	};
	//Specialisatin
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n----------------------------------------\n";
		//group[i]->print();
		//cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student)) cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate)) cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher)) cout << *dynamic_cast<Teacher*>(group[i]) << endl;
	}
	cout << "\n----------------------------------------\n";

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
}