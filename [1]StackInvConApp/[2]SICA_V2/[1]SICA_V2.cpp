#include <iostream>
#include <fstream>
using namespace std;

int max_students_storage = 0;
int top = -1;

void inputPushStudents(string students[], int &top);
void inputPopStudents(string students[], int &top);
void displayStudents(string students[]);
void displayMenu();
void displaySetStorage();
void clearScreen();

int main()
{
  bool programFlow = true;
  char userMenuChoice;

  displaySetStorage();

  string *students = new string[max_students_storage];

  while (programFlow)
  {
    displayMenu();
    cin >> userMenuChoice;

    switch (userMenuChoice)
    {
    case '0':
      clearScreen();
      inputPushStudents(students, top);
      break;

    case '1':
      clearScreen();
      displayStudents(students);
      break;

    case '2':
      clearScreen();
      inputPopStudents(students, top);
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

  delete[] students;

  return 0;
}

void inputPushStudents(string students[], int &top)
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|    Enrollment Management System   | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

  char continueInput;

  while (top < max_students_storage - 1)
  {
    cout << " [Student: Index " << top + 1 << "]: ";
    cin >> students[++top];

    ofstream outputFile("StudentData.txt");
    for (int i = 0; i <= top; i++)
    {
      outputFile << students[i] << endl;
    }
    outputFile.close();

    cout << " Add another student? (Y/N): ";
    cin >> continueInput;

    if (continueInput != 'Y' && continueInput != 'y')
    {
      break;
    }
  }

  if (top == max_students_storage - 1)
  {
    cout << " Array is full. Enrollment completed!\n";
  }
}

void inputPopStudents(string students[], int &top)
{
  if (top >= 0)
  {
    cout << "Removing student at Index " << top << ": " << students[top] << endl;
    top--;

    ofstream outputFile("StudentData.txt");
    for (int i = 0; i <= top; i++)
    {
      outputFile << students[i] << endl;
    }
    outputFile.close();
  }
  else
  {
    cout << " Array is empty.\n";
  }
}

void displayStudents(string students[])
{
  char homeChoice;
  do
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
         << "|    Enrollment Management System   | \n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    for (int i = 0; i <= top; i++)
    {
      cout << " [Student: Index " << i << "]:\t" << students[i] << "\n"
           << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    }
    cout << " [Enter 'h' to return home menu]: ";
    cin >> homeChoice;
    clearScreen();
  } while (homeChoice != 'h');
}

void displaySetStorage()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|    Enrollment Management System   | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|                                   | \n"
       << "|   Enter the maximum number of     | \n"
       << "|   enrolled students               | \n"
       << "|                                   | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "   Prompt >)> ";
  cin >> max_students_storage;
  clearScreen();
}

void displayMenu()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|    Enrollment Management System   | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|                                   | \n"
       << "|                       Storage:" << max_students_storage << "   | \n"
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

void clearScreen()
{
  cout << "\033[2J\033[1;1H"; // ANSI escape codes for clearing (For compatibility purposes)
}
