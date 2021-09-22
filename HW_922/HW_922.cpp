// HW_922.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
private:
    string firstName;
    string lastName;
    int grade;

public:
    Student(string first, string last, int g) //constructor
    {
        this->firstName = first;
        this->lastName = last;
        this->grade = g;
    }

    //public accessors
    string getFirst()
    {
        return firstName;
    }
    string getLast()
    {
        return lastName;
    }
    int getGrade()
    {
        return grade;
    }
};

bool myClass_sorter(Student& student_1, Student& student_2)
{
    if (student_1.getGrade() < student_2.getGrade())
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
    vector <Student> students; //create vector

    ifstream myfile("List.txt"); //call file

    //variables
    string currentLine;
    string first;
    string last;
    string grade;


    int pos_1;
    int pos_2;
    int pos_3;

    if (myfile.is_open()) //check for file
    {
        while (getline(myfile, currentLine)) //loop through each line
        {
            pos_1 = currentLine.find_first_of(" "); //find first white space

            pos_2 = currentLine.find_last_of(" "); //find last white space

            pos_3 = currentLine.size(); //use size of string as last position

            first = currentLine.substr(0, 0 + pos_1); //first name substring

            last = currentLine.substr(pos_1 + 1, pos_2 - pos_1 - 1); //last name substring

            grade = currentLine.substr(pos_2 + 1, pos_3 - pos_2); //grade substring

            int c_grade = stoi(grade);

            Student s(first, last, c_grade); //create object with components

            students.push_back(s); //push object inside vector
        }
    }
    else
    {
        cout << "Your file was not opened" << endl; //output message if file not found
    }

    sort(students.begin(), students.end(), &myClass_sorter);

    int sum = 0;

    int average = 0;

    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].getFirst() << " " << students[i].getLast() << " " << students[i].getGrade() << endl;

        sum += students[i].getGrade();
    }
    average = sum / students.size();

    cout << "Grade Average: " << average << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
