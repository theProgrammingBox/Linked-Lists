#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ios>

using namespace std;

struct StudentNode
{
	string name;
	int age;
	string major;
	float gpa;
	StudentNode* next;
};

void Input(StudentNode*& head, StudentNode* tail)
{
	StudentNode* temp;
	ifstream inFile;
	inFile.open("InFile.txt");

	while (inFile)
	{
		temp = new StudentNode;

		getline(inFile, temp->name);
		inFile >> temp->age;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inFile, temp->major);
		inFile >> temp->gpa;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}

		tail = temp;
		temp = NULL;
	}

	inFile.close();
}

void Search(StudentNode* head)
{
	string name;
	cout << "Enter student name: ";
	getline(cin, name);
	cout << endl;

	StudentNode* temp = head;
	bool found = false;

	while (temp != NULL && !found)
	{
		if (temp->name == name)
		{
			cout << "Name: " << temp->name << endl;
			cout << "Age: " << temp->age << endl;
			cout << "Major: " << temp->major << endl;
			cout << "GPA: " << temp->gpa << "\n\n";
			found = true;
		}
		temp = temp->next;
	}

	if (!found)
	{
		cout << "Student not found.\n\n";
	}
}

void Output(StudentNode* head)
{
	StudentNode* temp = head;

	while (temp != NULL)
	{
		cout << temp->name << endl;
		cout << temp->age << endl;
		cout << temp->major << endl;
		cout << temp->gpa << "\n\n";
		temp = temp->next;
	}
}

void RemoveFront(StudentNode*& head)
{
	StudentNode* temp = head;

	cout << "Removing\n";
	cout << temp->name << endl;
	cout << temp->age << endl;
	cout << temp->major << endl;
	cout << temp->gpa << "\n\n";

	if (head != NULL)
	{
		head = head->next;
		delete temp;
	}
}

float Average(StudentNode* head)
{
	StudentNode* temp = head;
	float sum = 0;
	int count = 0;

	while (temp != NULL)
	{
		sum += temp->gpa;
		count++;
		temp = temp->next;
	}

	return sum / count;
}