#pragma once
#include "Students.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subjects
{
private:
	vector<string> _subjects;
	void printSubName(string);
	void enterSubjectName(Subjects&, vector<string>&);
	void addSubjectName();

public:
	vector<string> getSubjects();
	void setSubjects(vector<string>&);

	vector<string> initSubjects(Subjects&);
	void addSubject(Subjects&, vector<string>&);
	string chooseSubject(vector<string>&, vector<vector<double>>&, Subjects&);
	void printSubjects(vector<string>& v);
};