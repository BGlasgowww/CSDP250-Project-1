#include "studentData.h"
#include<iostream>
#include<string>
using namespace std;

studentData::studentData() {
	head = nullptr;
};

void studentData::display() const {
	
	courseNode* nodePtr;
	nodePtr = head;

	while (nodePtr != nullptr) {
		cout << "Course Code: " << nodePtr->code << " " << "Credit Hours: " << nodePtr->credits << " " << "Grade: " << nodePtr->grades << endl;
		nodePtr = nodePtr->next;
	}
};

void studentData::add(string c, int h, char g, int count) {
	
	courseNode* post = new courseNode;

	post->code = c;
	post->credits = h;
	post->grades = g;
	post->next = nullptr;

	if (head == nullptr) {
		head = post;
	}

	c.erase(c.begin() + 0, c.end() - 5); //removes 'aaaa-'

	courseNode* current, *previous;
	current = head;
	previous = head-> next;

	for (int h = count; h >= 0; h--) {
		current = head;
		previous = head->next;
		for (int k= 0; k < count - 1; k++) {

			string b = previous->code;
			b.erase(b.begin() + 0, b.end() - 5);

			if (c > b) {
				swap(current->code, previous->code);
			}
			current = previous;
			previous = previous->next;
		}
	}

	count++;
	return;
};

void studentData::deleteSingle(string c, int count) {
	
	courseNode* nodePtr;
	courseNode* previous = nullptr;

	if (!head) {
		cout << "No data" << endl;
	}

	c.erase(c.begin() + 0, c.end() - 5);

	if (head->code == c) {
		courseNode* z = head;
		head = head->next;
		
		delete(z);

	}

	count--;
	return;
};

void studentData::deleteAll() {
	
	courseNode* nodePtr = nullptr;
	courseNode* nextPtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr) {
		nextPtr = nodePtr->next;
		delete nodePtr;
	}
};

studentData::~studentData() {
	
	deleteAll();

};


