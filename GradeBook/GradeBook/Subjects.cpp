#include "Subjects.h"
#include "Students.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> Subjects::getSubjects() {
	return _subjects;
}

void Subjects::setSubjects(vector<string>& v) {
	for (auto i : v) {
		_subjects.push_back(i);
	}
}

vector<string> Subjects::initSubjects(Subjects& sub) {
	vector<string> v{};
	readFromFile(v, "subjects");
	sub.setSubjects(v);
	v = sub.getSubjects();
	return v;
}

string Subjects::chooseSubject(vector<string>& v1, vector<vector<double>>& v2, Subjects& sub) {
	cout << "\nChoose subject (enter number) :\t";
	int num{};

	while (1) {
		num = getNumber();
		try {
			if (num > v1.size() || num == 0)
				throw 0;
			else
				break;
		}
		catch (int& ex) {
			cerr << "Enter a number between 1 and " << v1.size() << "!\t";
		}
	}
	sub.printSubName(v1.at(num - 1));
	auto it = find(v1.begin(), v1.end(), (v1.at(num - 1)));
	readFromFile(v2, v1.at(it - v1.begin()));
	return v1.at(num - 1);
}

void Subjects::printSubjects(vector<string>& v) {
	cout << "\nList of all subjects : " << endl;
	print(v);
}

void Subjects::printSubName(string s) {
	cout << "\n| ~ " << setw(3) << s << " ~ |" << endl;
}

void Subjects::addSubjectName() {
	string subject{};

	while (1) {
		getline(cin, subject);
		if (subject.size() > 1) {
			string s = subject + ".txt";
			fstream file;
			file.open(s, ios::out);
			_subjects.push_back(subject);
			file.close();
			break;
		}
		else {
			cout << "You haven't typed anything. Try again! :\t";
		}
	}
}

void Subjects::enterSubjectName(Subjects& sub, vector<string>& v) { //priv
	sub.addSubjectName();
	v = sub.getSubjects();
	sub.printSubjects(v);
	writeIntoFile(v, "subjects");
}

void Subjects::addSubject(Subjects& sub, vector<string>& v) {
	if (sub.getSubjects().size() == 0) {
		cout << "List of the subjects is empty. Enter a name of a new subject :\t";
		sub.enterSubjectName(sub, v);
	}
	else {
		cout << "\nWould you like to add a new subject? (y/n) :\t";
		string s{};

		while (1) {
			try {
				cin >> s;
				if (s == "y") {
					cout << "Enter a name of a new subject :\t";
					cin.ignore();
					sub.enterSubjectName(sub, v);
					break;
				}
				else if (s == "n") {
					break;
				}
				else {
					throw 0;
				}
			}
			catch (int& ex1) {
				cout << "Enter 'y' or 'n'!\t";
			}
		}
	}
}