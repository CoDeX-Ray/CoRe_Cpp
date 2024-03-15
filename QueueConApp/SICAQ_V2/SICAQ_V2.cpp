#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class Student
{
public:
  string fullName;
  string ID;
  string department;
  int age;
  string birthday;
  string address;
};

void runProgram(queue<Student> &studentsQueue);
void inputEnqueueStudent(queue<Student> &studentsQueue);
void inputDequeueStudent(queue<Student> &studentsQueue);
void displayStudents(const queue<Student> &studentsQueue);
void displayMenu();
void clearScreen();

int main()
{
  queue<Student> studentsQueue;
  runProgram(studentsQueue);

  return 0;
}

void inputEnqueueStudent(queue<Student> &studentsQueue)
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|       Enrollment Management System      | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

  char continueInput;

  do
  {
    Student newStudent;

    cout << " [Full Name]: ";
    cin.ignore();
    getline(cin, newStudent.fullName);

    cout << " [ID]: ";
    cin >> newStudent.ID;

    cout << " [Department]: ";
    cin.ignore();
    getline(cin, newStudent.department);

    cout << " [Age]: ";
    cin >> newStudent.age;

    cout << " [Birthday]: ";
    cin.ignore();
    getline(cin, newStudent.birthday);

    cout << " [Address]: ";
    getline(cin, newStudent.address);

    studentsQueue.push(newStudent);

    ofstream outputFile("StudentData.txt", ios::app);
    outputFile << newStudent.fullName << ","
               << newStudent.ID << ","
               << newStudent.department << ","
               << newStudent.age << ","
               << newStudent.birthday << ","
               << newStudent.address << endl;
    outputFile.close();

    cout << " Add another student? (Y/N): ";
    cin >> continueInput;

  } while (continueInput == 'Y' || continueInput == 'y');
}

void inputDequeueStudent(queue<Student> &studentsQueue)
{
  if (!studentsQueue.empty())
  {
    cout << "Removing student: " << studentsQueue.front().fullName << endl;

    queue<Student> tempQueue = studentsQueue;
    tempQueue.pop();

    ofstream outputFile("StudentData.txt");
    while (!tempQueue.empty())
    {
      outputFile << tempQueue.front().fullName << ","
                 << tempQueue.front().ID << ","
                 << tempQueue.front().department << ","
                 << tempQueue.front().age << ","
                 << tempQueue.front().birthday << ","
                 << tempQueue.front().address << endl;
      tempQueue.pop();
    }
    outputFile.close();

    studentsQueue.pop();
  }
  else
  {
    cout << " Queue is empty.\n";
  }
}

void displayStudents(const queue<Student> &studentsQueue)
{
  char homeChoice;
  do
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
         << "|       Enrollment Management System      | \n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

    queue<Student> tempQueue = studentsQueue;

    while (!tempQueue.empty())
    {
      const Student &currentStudent = tempQueue.front();

      cout << " [Full Name]:  " << currentStudent.fullName << "\n"
           << " [ID]:         " << currentStudent.ID << "\n"
           << " [Department]: " << currentStudent.department << "\n"
           << " [Age]:        " << currentStudent.age << "\n"
           << " [Birthday]:   " << currentStudent.birthday << "\n"
           << " [Address]:    " << currentStudent.address << "\n"
           << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

      tempQueue.pop();
    }

    cout << " [Enter 'h' to return home menu]: ";
    cin >> homeChoice;
    clearScreen();

  } while (homeChoice != 'h');
}

void displayMenu()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|      Enrollment Management System     | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|                                       | \n"
       << "|      Menu:                            | \n"
       << "|      [0] Enroll New Student           | \n"
       << "|      [1] Display Enrolled Students    | \n"
       << "|      [2] Remove Student               | \n"
       << "|      [3] Terminate Program            | \n"
       << "|                                       | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "   Select menu >)> ";
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H"; // ANSI escape codes for clearing (For compatibility purposes)
}

void runProgram(queue<Student> &studentsQueue)
{
  bool programFlow = true;
  char userMenuChoice;

  while (programFlow)
  {
    displayMenu();
    cin >> userMenuChoice;

    switch (userMenuChoice)
    {
    case '0':
      clearScreen();
      inputEnqueueStudent(studentsQueue);
      break;

    case '1':
      clearScreen();
      displayStudents(studentsQueue);
      break;

    case '2':
      clearScreen();
      inputDequeueStudent(studentsQueue);
      break;

    case '3':
      programFlow = false;
      cout << "   Program Terminated!";
      break;

    default:
      cout << " Invalid choice! \n";
      break;
    }
  }
}
