#include "Students.h"
#include "Subjects.h"
#include "Utils.h"
#include "Windows.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

vector<string> Students::getNames() {
	return _names;
}

void Students::setNames(vector<string>& v) {
	for (auto i : v) {
		_names.push_back(i);
	}
}

vector<string> Students::initStudents(Students& s) {
	vector<string> v = {};
	readFromFile(v, "names");
	s.setNames(v);
	v = s.getNames();
	return v;
}

void Students::addName(string s) {
	for (int i = 0; i < _names.size(); i++) {
		if (_names.at(i) == " ")
			_names.erase(_names.begin() + i - 1);
	}
	_names.push_back(s);
}

void Students::addStudent(vector<string>& v1, vector<vector<double>>& v2, Students& s) {
	cout << "Add new student : " << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	addName(name);
	v1 = s.getNames();
	v2.resize((v1.size()));
}

void Students::addGrade(vector<vector<double>>& v, vector<string>& v2) {
	cout << "\n > Enter a number from the list :\t";
	int num{};

	while (1) {
		num = getNumber();
		try {
			if (num < v2.size() + 1) {
				int index = num - 1;
				string s{};
				cout << "\nEnter grade to add :\t";

				while (1) {
					cin >> s;

					if ((s == "2.0") || (s == "3.0") || (s == "3.5") || (s == "4.0") || (s == "4.5") || (s == "5.0")) {
						double score = stod(s);

						v.resize(v2.size());
						v.at(index).push_back(score);
						break;
					}
					else {
						cout << "Wrong grade! Try again!\t";
					}
				}
				break;
			}
			else {
				throw 0;
			}
		}
		catch (int& ex) {
			cerr << "Enter a number between 1 and " << v2.size() << "!\t";
		}
	}
}

void Students::printList(vector<vector<double>>& v1, vector<string>& v2) {
	cout << endl;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < v2.size(); i++) {
		cout << i + 1 << ". " << v2.at(i) << " ~ ";

		v1.resize((v2.size()));
		print(v1, i);
		cout << "\n\t | Avarage : " << calcAvarage(v1.at(i));
		cout << " | Final grade : ";
		if (calcFinalGrade(calcAvarage(v1.at(i))) == 2.0) {
			setColorRed(hOut);
			cout << calcFinalGrade(calcAvarage(v1.at(i))) << endl << endl;
			setColorStandard(hOut);
		}
		else
			cout << calcFinalGrade(calcAvarage(v1.at(i))) << endl << endl;
	}
}

double Students::calcAvarage(vector<double>& v) {
	double a{ 0 };
	cout << fixed << setprecision(2);
	for (int i = 0; i < v.size(); i++) {
		a += v.at(i);
	}
	if (v.size() == 0)
		a = 0.0;
	else
		a /= v.size();
	return a;
}

double Students::calcFinalGrade(double a) {
	if (a < 2.75)
		return 2.0;
	else if (a >= 2.75 && a < 3.25)
		return 3.0;
	else if (a >= 3.25 && a < 3.75)
		return 3.5;
	else if (a >= 3.75 && a < 4.25)
		return 4.0;
	else if (a >= 4.25 && a < 4.75)
		return 4.5;
	else if (a >= 4.75)
		return 5.0;
}