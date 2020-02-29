#pragma once
#include "Subjects.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subjects;

class Students
{
private:
	vector<string> _names;
	void addName(string);
	double calcAvarage(vector<double>&);
	double calcFinalGrade(double);

public:
	vector<string> getNames();
	void setNames(vector<string>&);

	vector<string> initStudents(Students&);
	void addStudent(vector<string>&, vector<vector<double>>&, Students&);
	void addGrade(vector<vector<double>>&, vector<string>&);
	void printList(vector<vector<double>>&, vector<string>&);
};