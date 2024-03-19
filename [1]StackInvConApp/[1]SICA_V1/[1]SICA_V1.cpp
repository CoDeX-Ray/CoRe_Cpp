#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
void enrollStudent(string *studentName, int &top, const string &name)
{
  if (top < MAX_STUDENTS - 1)
  {
    studentName[++top] = name;
    cout << "Enrolled student successfully.\n";
  }
  else
  {
    cout << "Enrollment is full. Cannot enroll more students.\n";
  }
}

void pop(string *studentName, int &top)
{
  if (top >= 0)
  {
    cout << "Removed student from enrollment: " << studentName[top--] << "\n";
  }
  else
  {
    cout << "Enrollment is empty. Cannot remove more students.\n";
  }
}

void displayEnrollment(const string *studentName, int top)
{
  cout << "Enrollment:\n";
  for (int i = 0; i <= top; ++i)
  {
    cout << "Student Name: " << studentName[i] << "\n";
  }
}

void displayMenu()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|                                   | \n"
       << "|    Enrollment Management System   | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|  Author:  RAYMUND                 | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|                                   | \n"
       << "|  Menu:                            | \n"
       << "|  [0] Enroll New Student           | \n"
       << "|  [1] Display Enrolled Students    | \n"
       << "|  [2] Remove Student               | \n"
       << "|  [3] Terminate Program            | \n"
       << "|                                   | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "   Select menu >)> ";
}

int main()
{
  char choice;
  string newName;
  int maxStudents;

  cout << "Enter the maximum number of students: ";
  cin >> maxStudents;

  string *studentName = new string[maxStudents];
  int top = -1;

  do
  {
    displayMenu();
    cin >> choice;

    switch (choice)
    {
    case '0':
      cout << "Enter student name: ";
      cin >> newName;
      enrollStudent(studentName, top, newName);
      break;

    case '1':
      displayEnrollment(studentName, top);
      break;

    case '2':
      pop(studentName, top);
      break;

    case '3':
      cout << "Terminating the enrollment system.\n";
      break;

    default:
      cout << "Invalid choice. Please try again.\n";
    }

  } while (choice != '3');

  delete[] studentName;

  return 0;
}
