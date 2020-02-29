#include "Students.h"
#include "Subjects.h"
#include "Utils.h"
#include <Windows.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <ios>
#include <string>
#include <fstream>
using namespace std;

void setColorRed(HANDLE h) {
	SetConsoleTextAttribute(h, FOREGROUND_RED);
}

void setColorStandard(HANDLE h) {
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void print(vector<string>& v) {
	int n = 1;
	for (auto i : v) {
		cout << n << ". " << i << endl;
		n++;
	}
}

void print(vector<vector<double>>& v, int x) {
	for (int i = 0; i < v.at(x).size(); i++) {
		cout << fixed << setprecision(1) << v.at(x).at(i) << " ";
	}
}

void dispWelcome() {
	cout << "\t-----------------------------------------" << endl;
	cout << "\t| Welcome to the GradeBook application! |" << endl;
	cout << "\t-----------------------------------------" << endl;

}

int selectOption() {
	int a = getNumber();
	return a;
}

void displayOptions() {
	cout << "\n\t(1) add new student to the list" << endl;
	cout << "\t(2) add grades" << endl;
	cout << "\t(3) change subject" << endl;
	cout << "\t(4) exit application & save changes\n" << endl;
	cout << " > Your choice :\t";
}

bool isNumber(string& s) // checks if string is an int
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) {
		++it;
	}
	return !s.empty() && it == s.end();
}

int getNumber() { // function convertibng string to int
	string s{};
	while (1) {
		cin >> s;
		if (isNumber(s) == 0) {
			cout << "It's not a number! Try again! \t";
		}
		else {
			int a = stoi(s);
			return a;
			break;
		}
	}
}

void save(vector<string>& v1, vector<string>& v2, Subjects& sub, Students& s) {
	v1 = sub.getSubjects();
	v2 = s.getNames();
	writeIntoFile(v1, "subjects");
	writeIntoFile(v2, "names");
}

void readFromFile(vector<string>& v, string s) {
	fstream names;
	names.open(s + ".txt");
	string line{};

	if (names.is_open()) {
		while (getline(names, line))
			v.push_back(line);
		names.close();
	}
	else {
		cout << "We couldn't open a file! " << endl;
		exit(0);
	}
}

void writeIntoFile(vector<string>& v, string s) {
	ofstream names;
	names.open(s + ".txt");

	if (names.is_open()) {
		for (string s : v)
			names << s << endl;
		names.close();
	}
	else {
		cout << "We couldn't open a file! " << endl;
		exit(0);
	}
}

void writeIntoFile(vector<vector<double>>& v, string s) {
	ofstream file;
	file.open(s + ".txt");

	if (file.is_open()) {
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.at(i).size(); j++)
				file << fixed << setprecision(1) << v.at(i).at(j) << " ";
			file << endl;
		}
		file.close();
	}
	else {
		cout << "We couldn't open a file! " << endl;
		exit(0);
	}
}

void readFromFile(vector<vector<double>>& v, string s) { // podajemy wektor do którego zapisujemy
	vector<string> scores_s{};

	fstream file;
	file.open(s + ".txt");

	if (file.is_open()) {
		string line{};

		while (getline(file, line))
			scores_s.push_back(line);

		string linia{}, score{};

		for (int j = 0; j < scores_s.size(); j++) {
			linia = scores_s.at(j);

			for (int i = 0; i < linia.length(); i = i + 4) { // wyci¹ganie ocen ze stringa i wpisywanie do wektora 2d
				score = linia.substr(i, 4);
				v.at(j).push_back(stod(score));
			}
		}
		file.close();
	}
	else {
		cout << "We couldn't open a file! " << endl;
		exit(0);
	}
}