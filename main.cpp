#include"studentData.h"
#include<iostream>
#include<string>
using namespace std;

int main() {

	int menuChoice, h, count = -1;
	studentData s;
	string c;
	char g;

	cout << "This program will allow you to record the courses a student has completed in their bachelor program!" << endl;

menu1:
	cout << "Home Menu" << endl;
	cout << "1) Add Course." << endl;
	cout << "2) Delete Course." << endl;
	cout << "3) Display the list." << endl;
	cout << "4) Delete all nodes." << endl;
	cout << "5) Exit Program." << endl;

	do {
		cout << "Enter (1-5): " << endl;
		cin >> menuChoice;
	} while (menuChoice == 0 || menuChoice > 5);

	while (menuChoice == 1) {
		cout << "What is the course code (aaaa-000): ";
		cin.ignore();
		getline(cin, c);

		do {
			cout << "How many credit hours: ";
			cin >> h;
		} while (h <= 0 || h > 5);

		cout << "What was your grade: ";
		cin.ignore();
		cin >> g;

		s.add(c, h, g, count);

		goto menu1;
	}

	while (menuChoice == 2) {
		
		cout << "Which course would you like to delete?: " << endl;
		cin.ignore();
		getline(cin, c);

		s.deleteSingle(c, count);

		goto menu1;
	}

	while (menuChoice == 3) {

		s.display();

		goto menu1;
	}

	while (menuChoice == 4) {

		s.deleteAll();

		goto menu1;
	}
	
	while (menuChoice == 5) {

		s.deleteAll();
		exit(0);

	}

}
