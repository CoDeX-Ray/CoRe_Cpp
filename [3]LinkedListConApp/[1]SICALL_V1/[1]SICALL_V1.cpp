#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
  int age;
  string fullName;
  string ID;
  string department;
  string birthday;
  string address;

  Student(const string &name, const string &id, const string &dept, int studentAge, const string &dob, const string &addr)
      : fullName(name), ID(id), department(dept), age(studentAge), birthday(dob), address(addr) {}
};

class ListNode
{
public:
  Student student;
  ListNode *next;

  ListNode(const Student &newStudent) : student(newStudent), next(nullptr) {}
};

class LinkedList
{
private:
  ListNode *head;

public:
  LinkedList() : head(nullptr) {}

  void append(const Student &newStudent)
  {
    ListNode *newNode = new ListNode(newStudent);
    if (!head)
    {
      head = newNode;
    }
    else
    {
      ListNode *current = head;
      while (current->next)
      {
        current = current->next;
      }
      current->next = newNode;
    }

    ofstream outputFile("StudentData.txt", ios::app);
    outputFile << newStudent.fullName << ","
               << newStudent.ID << ","
               << newStudent.department << ","
               << newStudent.age << ","
               << newStudent.birthday << ","
               << newStudent.address << endl;
    outputFile.close();
  }

  void removeFront()
  {
    if (head)
    {
      ListNode *temp = head;
      head = head->next;
      delete temp;

      ofstream outputFile("StudentData.txt");
      ListNode *current = head;
      while (current)
      {
        outputFile << current->student.fullName << ","
                   << current->student.ID << ","
                   << current->student.department << ","
                   << current->student.age << ","
                   << current->student.birthday << ","
                   << current->student.address << endl;
        current = current->next;
      }
      outputFile.close();
    }
    else
    {
      cout << " List is empty.\n";
    }
  }

  void display() const
  {
    char homeChoice;
    do
    {
      clearScreen();

      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
           << "|       Enrollment Management System      | \n"
           << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

      ListNode *current = head;

      while (current)
      {
        const Student &currentStudent = current->student;

        cout << " [Full Name]:  " << currentStudent.fullName << "\n"
             << " [ID]:         " << currentStudent.ID << "\n"
             << " [Department]: " << currentStudent.department << "\n"
             << " [Age]:        " << currentStudent.age << "\n"
             << " [Birthday]:   " << currentStudent.birthday << "\n"
             << " [Address]:    " << currentStudent.address << "\n"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

        current = current->next;
      }

      cout << " [Enter 'h' to return to the main menu]: ";
      cin >> homeChoice;
    } while (homeChoice != 'h');
  }

  ~LinkedList()
  {
    ListNode *current = head;
    while (current)
    {
      ListNode *temp = current;
      current = current->next;
      delete temp;
    }
  }

  void clearScreen() const
  {
    cout << "\033[2J\033[1;1H"; // ANSI escape codes for clearing (For compatibility purposes)
  }
};

void inputEnqueueStudent(LinkedList &studentsList);
void inputDequeueStudent(LinkedList &studentsList);
void displayMenu();

int main()
{
  LinkedList studentsList;
  bool programFlow = true;
  char userMenuChoice;

  while(programFlow)
  {
    displayMenu();
    cin >> userMenuChoice;

    switch (userMenuChoice)
    {
    case '0':
      studentsList.clearScreen();
      inputEnqueueStudent(studentsList);
      break;

    case '1':
      studentsList.clearScreen();
      studentsList.display();
      break;

    case '2':
      studentsList.clearScreen();
      inputDequeueStudent(studentsList);
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
  return 0;
}

void inputEnqueueStudent(LinkedList &studentsList)
{
  cout << "Enter student details:\n";

  string name, id, dept, birthday, address;
  int age;

  cout << " [Full Name]: ";
  cin.ignore();
  getline(cin, name);

  cout << " [ID]: ";
  cin >> id;

  cout << " [Department]: ";
  cin.ignore();
  getline(cin, dept);

  cout << " [Age]: ";
  cin >> age;

  cout << " [Birthday]: ";
  cin.ignore();
  getline(cin, birthday);

  cout << " [Address]: ";
  getline(cin, address);

  Student newStudent(name, id, dept, age, birthday, address);
  studentsList.append(newStudent);

  cout << "   Student added successfully!\n";
}

void inputDequeueStudent(LinkedList &studentsList)
{
  studentsList.removeFront();
  cout << "   Student removed successfully!\n";
}

void displayMenu()
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "|       Enrollment Management System      | \n"
       << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n"
       << "|                                         | \n"
       << "|       Menu:                             | \n"
       << "|       [0] Enroll New Student            | \n"
       << "|       [1] Display Enrolled Students     | \n"
       << "|       [2] Remove Student                | \n"
       << "|       [3] Terminate Program             | \n"
       << "|                                         | \n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
       << "   Select menu >)> ";
}
