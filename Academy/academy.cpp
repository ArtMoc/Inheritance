#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduate.h"


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
		group[i]->print();
	}
	cout << "\n----------------------------------------\n";

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
}