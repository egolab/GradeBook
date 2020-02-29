#include "Students.h"
#include "Subjects.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	Students students;
	Subjects subjects;

	vector<string> names = students.initStudents(students);
	vector<string> sub = subjects.initSubjects(subjects);

	vector<vector<double>> tmp{};

	while (1) {
		dispWelcome();
		subjects.printSubjects(sub);
		subjects.addSubject(subjects, sub);
		sub = subjects.getSubjects();
		tmp.clear();
		tmp.resize(names.size());
		string s = subjects.chooseSubject(sub, tmp, subjects);
		students.printList(tmp, names);
		displayOptions();

		while (1) {
			try {
				int a = selectOption();

				if (a == 1) { // add new student to the list
					students.addStudent(names, tmp, students);
					writeIntoFile(names, "names");
					students.printList(tmp, names);
					displayOptions();
				}

				else if (a == 2) { // add grades
					students.addGrade(tmp, names);
					writeIntoFile(tmp, s);
					students.printList(tmp, names);
					displayOptions();
				}

				else if (a == 3) { // change subject
					system("cls");
					break;
				}
				else if (a == 4) { // exit application & save changes
					save(sub, names, subjects, students);
					exit(0);
				}
				else {
					throw 0;
				}
			}
			catch (int& ex) {
				cout << "Enter number between 1 and 4!\t";
			}
		}
	}
}