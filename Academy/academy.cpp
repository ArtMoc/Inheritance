
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define tab "\t"

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
	virtual ~Human()
	{
		cout << "H_Destructor:\t" << this << endl;
	}
	//                METHODS:
	virtual ostream& print(ostream& os)const
	{
		return os
			<< left << setw(12) << last_name
			<< left << setw(3) << "|"
			<< left << setw(12) << first_name
			<< left << setw(3) << "|"
			<< left << setw(5) << age << " лет\t| "; ///???????????

		/*os.width(10);
		os << std::left;
		os << last_name;
		os.width(10);
		os << std::left;////////////SECOND METHOD OF EVEN
		os << first_name;
		os.width(5);
		os << age;
		return os;*/
	}
	virtual ofstream& print(ofstream& os)const
	{
		os.width(15);
		os << left;
		os << typeid(*this).name() << " | ";
		os.width(10);
		os << std::left;
		os << last_name << "|";
		os.width(10);
		os << std::left;////////////SECOND METHOD OF EVEN-2
		os << first_name << "|";
		os.width(5);
		os << age << "|";
		return os;
	}
	virtual istream& input(istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
	virtual ifstream& input(ifstream& is)
	{
		std::getline(is, last_name, '|');
		std::getline(is, first_name, '|');
		string age_buffer;
		std::getline(is, age_buffer, '|');
		this->age = std::stoi(age_buffer);//stoi - преобразует строку в число
		return is;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}
istream& operator>>(istream& is, Human& obj)
{
	return obj.input(is);
}
ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.input(is);
}


class Student :public Human
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
	) :Human(last_name, first_name, age)//Делегируем конструктор базового класса
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
	ostream& print(ostream& os)const
	{
		Human::print(os);
		return os
			<< left << setw(12) << speciality
			<< left << setw(5) << "|"
			<< left << setw(10) << group
			<< left << setw(5) << "|"
			<< left << setw(5) << rating << left << setw(5) << "%";

		/*os.width(15);
		os << left;
		os << speciality;///////SECOND METHOD OF EVEN
		os.width(8);
		os << left;
		os << group;
		os.width(5);
		os<<rating << "%";
		return os;*/
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		/*return os
			<< left << setw(12) << speciality
			<< left << setw(5) << "|"
			<< left << setw(10) << group
			<< left << setw(5) << "|"
			<< left << setw(5) << rating << left << setw(5) << "%";*/
		
		os.width(25);
		os << left;
		os << speciality<<"|";///////SECOND METHOD OF EVEN
		os.width(8);
		os << left;
		os << group << "|";
		os.width(5);
		os << internal;
		os << rating;
		os << "% |";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> speciality;
		is >> group;
		is >> rating;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, speciality, '|');
		std::getline(is, group, '|');
		string rating_buffer;
		std::getline(is, rating_buffer, '|');
		this->rating = std::stod(rating_buffer); // stod - преобразует string в double
		return is;
	}
};
class Teacher :public Human
{
	string speciality;
	string group;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}


	//                  CONSTRUCTORS:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_experience(experience);
		cout << "T_Constructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "T_Destructor:\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);

		return os
			<< left << setw(12) << speciality
			<< left << setw(5) << "|"
			<< left << setw(10) << group
			<< left << setw(5) << "|"
			<< left << setw(5) << experience << "лет";
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);

		/*return os
			<< left << setw(12) << speciality
			<< left << setw(5) << "|"
			<< left << setw(10) << group
			<< left << setw(5) << "|"
			<< left << setw(5) << experience << "лет";*/
		os.width(33);
		os << speciality << " | ";
		os.width(5);
		os << right;
		os << experience << " | ";
		return os;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, speciality, '|');
		string xp_buffer;
		std::getline(is, xp_buffer, '|');
		experience = std::stod(xp_buffer);
		return is;
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
	ostream& print(ostream& os)const
	{
		Student::print(os);
		return os << left << setw(5) << "|" << "Theme of the diploma: " << subject;
	}
	ofstream& print(ofstream& os)const
	{
		Student::print(os);
		os << left << " " << subject;
		return os;
	}
	ifstream& input(ifstream& is)
	{
		Student::input(is);
		std::getline(is, subject);
		return is;
	}

};

void SaveToFile(Human* group[], const int size, const string& filename);
void Print(Human* group[], const int size);
Human** LoadFromFile(const std::string& filename);
Human* HumanFactory(const std::string& human_type);


//#define INHERITANCE
//#define OUTPUT_CHECK

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
#ifdef OUTPUT_CHECK
	const Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),//upcast
		new Student("Vercetti", "Tomas", 30, "Cryminal", "Vice", 90),//upcast
		new Student("Diaz", "Ricardo", 55, "Weapons", "Vice", 80),
		new Teacher("White", "Walter", 50, "Chemistry", "Опыт ", 25),//upcast
		new Teacher("Eistein", "Albert", 143, "Astronomy", "Опыт ", 120),
		new Graduate("Schrader", "Hank", 42,
		"Cryminal", "OBN", 95,	"How to catch Heisenberg")
	};
	//Specialisatin
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n----------------------------------------\n";
		//group[i]->print();
		cout << *group[i] << endl;
	}
	cout << "\n----------------------------------------\n";

	/*ofstream fout("Group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad Group.txt");*/
	string filename = "Group.txt";
	SaveToFile(group, sizeof(group) / sizeof(group[0]), "Group.txt");
	system((string("notepad ")+filename).c_str()); 
	// string("notepad ") - ПРЕОБРАЗУЕМ СТРОКОВУЮ КОНСТАНТУ "notepad " В ОБЪЕКТ КЛАССА std::string
	// string("notepad ")+filename - ВЫПОЛНЯЕМ КОНКАТЕНАЦИЮ ДВУХ ОБЪЕКТОВ КЛАССА std::string
	// (std::string).c_str() - МЕТОД c_str() ВОЗВРАЩАЕТ СОДЕРЖИМОЕ ОБЪЕКТА std::string 
	//     В ВИДЕ ОБЫЧНОЙ NULL Terminated Line  (C-String), ТО ЕСТЬ В ВИДЕ МАССИВА ЭЛЕМЕНТОВ char.

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
#endif // OUTPUT_CHECK

	/*Human human("last_name", "first_name", 0);
	cout << "Кто к нам пришел: ";
	cin >> human;
	cout << human << endl;*/

	/*Student stud("", "", 0, "", "", 0);
	cout << "Кто к нам пришел: ";
	cin >> stud;
	cout << stud;*/

	Human** group = LoadFromFile("Group.txt");
	Print(group, 6);
}

void SaveToFile(Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();	
}

void Print(Human* group[], const int size)
{
	
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}	
}

Human** LoadFromFile(const std::string& filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		// 1) Вычисляем размер файла
		std::string buffer; //В этот буфер будем читать строки из файла
		int n = 0; // Количество строк в файле
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			n++;
		}
        // 2) Выделяем память под массив группу
		Human** group = new Human * [n] {};
		// 3) Возвращаем курсор в начало файла для того, чтобы заново его прочитать
		fin.clear();
		fin.seekg(0);
		//4) ЗАново читаем файл и загружаем его содержимое в массив объектов
		string human_type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, human_type, '|');
			//cout << buffer << endl;
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
		fin.close();
		return group;

	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr; //Если файл прочитать не удалось, возрващаем указатель на 0
}

Human* HumanFactory(const std::string& human_type)
{
	if (human_type.find ("class Student")!=string::npos)return new Student("last_name", "first_name", 0, "spec", "group", 0);
	if (human_type.find("class Graduate")!=string::npos)return new Graduate("last_name", "first_name", 0, "spec", "group", 0, "subj");
	if (human_type.find("class Teacher")!=string::npos)return new Teacher("last_name", "first_name", 0, "spec", "group", 0);
	return nullptr;

}