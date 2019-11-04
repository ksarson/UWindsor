/*  Name:     Kolby Sarson
    SID:      104232327
    Homework: Assignment 2
    Due Date: January 28, 2018
    Class:    COMP 3400
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct employee
{
  unsigned id;
  string name;
  double salary;
};

istream& operator >>(istream& is, employee& e)
{
  return is >> e.id >> e.name >> e.salary;
}

ostream& operator <<(ostream& os, employee const& e)
{
  return os << e.id << ' ' << e.name << ' ' << e.salary;
}

ostream& operator <<(ostream& os, vector<employee> const& v)
{
  string str = "";
  for (auto e=v.begin(); e!=v.end(); ++e){
      str += '(' + to_string(e->id) + ',' + e->name + ',' + to_string(e->salary) + ')';
  }
  return os << str;
}

int main()
{
  vector<employee> employees;
  employee emp;
  while (cin >> emp){
      employees.push_back(emp);
  }

  if (!cin.eof())
  {
    cerr << "ERROR: Invalid input. Aborting." << endl;
    return 1;
  }
  cout << "     RAW_DATA: " << employees << endl;

  {
    vector<employee> employees_copy(employees);
    stable_sort(employees_copy.begin(), employees_copy.end(), 
      [](employee const& e1, employee const& e2){return e1.name < e2.name;});
    cout << "      BY_NAME: " << employees_copy << endl;
  }

   stable_sort(employees.begin(), employees.end(), 
      [](employee const& e1, employee const& e2){return e1.salary < e2.salary;});
  cout << "    BY_SALARY: " << employees << endl;

  auto low_end = find_if(employees.begin(), employees.end(), [](employee emp){return (emp.salary >= 20000 && emp.salary <= 30000);});
  auto upper_end = find_if(low_end, employees.end(), [](employee emp){return (emp.salary < 20000 && emp.salary > 30000);});

  for (auto i = low_end; i != upper_end; ++i)
    i->salary *= 1.02;
  cout << "SALARY_ADJUST: " << employees << endl;

  reverse(low_end, upper_end);
  cout << "AFTER_REVERSE: " << employees << endl;
}

