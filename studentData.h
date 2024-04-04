#pragma once
#include<string>
#include<iostream>
using namespace std;

class studentData {
private:
	struct courseNode {
		string code;
		int credits;
		char grades;
		courseNode* next;
	}; courseNode* head;
	
public:
	studentData();

	void add(string, int, char, int count);
	void deleteSingle(string, int);
	void deleteAll();
	void display() const;

	~studentData();
};


