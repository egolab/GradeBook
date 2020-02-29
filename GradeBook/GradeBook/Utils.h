#pragma once
#include "Students.h"
#include "Subjects.h"
#include <Windows.h>

void dispWelcome();
void displayOptions();
int selectOption();
void setColorRed(HANDLE);
void setColorStandard(HANDLE);
bool isNumber(string&);
int getNumber();
void save(vector<string>&, vector<string>&, Subjects&, Students&);

void print(vector<vector<double>>&, int);
void print(vector<string>&);

void readFromFile(vector<string>&, string);
void writeIntoFile(vector<string>&, string);
void readFromFile(vector<vector<double>>&, string);
void writeIntoFile(vector<vector<double>>&, string);