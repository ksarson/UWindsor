/*  Name:     Kolby Sarson
    SID:      104232327
    Homework: Assignment 2
    Due Date: January 28, 2018
    Class:    COMP 3400
*/

// add needed #include files here
//#error write code here
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
  // write code to read in an employee, i.e.,
  //   e.id followed by e.name followed by e.salary.
  return is >> e.id >> e.name >> e.salary;
}

ostream& operator <<(ostream& os, employee const& e)
{
  // write code to output an employee, i.e.,
  //   e.id followed by a ' ', followed by 
  //   e.name followed by a ' ', followed by
  //   e.salary.
  return os << e.id << ' ' << e.name << ' ' << e.salary;
}

//---

ostream& operator <<(ostream& os, vector<employee> const& v)
{
  // write code to output v with each employee here as follows:
  //  '(', followed by e.id, followed by ',', 
  //  followed by e.name, followed by ',',
  //  followed by e.salary, followed by ')'.
  // with no space(s) before or after such.
  string str = "";
  for (auto e=v.begin(); e!=v.end(); ++e){
      str += '(' + to_string(e->id) + ',' + e->name + ',' + to_string(e->salary) + ')';
  }
  return os << str;
}

//---

int main()
{
  vector<employee> employees; // declare a sequence of employee records

  // read in all employees from cin (until end-of-file or an error)
  //   * using a for or while loop
  //   * with a 1-line for/while loop body calling:
  //       employees.push_back( /* employee record variable */) to
  //     to add each employee record.
  // APPROX # of lines of code: 3 (with "while" loop); 2 (with "for" loop)
  employee emp;
  while (cin >> emp){
      employees.push_back(emp);
  }

  // abort if we did not reach the end-of-file, i.e., an error occurred...
  if (!cin.eof())
  {
    cerr << "ERROR: Invalid input. Aborting." << endl;
    return 1;
  }

  // output the employee records read in...
  cout << "     RAW_DATA: " << employees << endl;

  // create a local scope for some short-lived variables...
  {
    // make a copy of employees (in another variable)...
    //   HINT 1: The variable type is still vector<employee>.
    //   HINT 2: Choose the variable name you want to use.
    //           I will use the name "employees_copy" in subsequent
    //           comments to refer to this variable.
    //   HINT 3: Pass the employees variable to the copy constructor.
    //   HINT 4: This is a single-line of code, i.e., a variable declaration
    //           invoking the copy constructor.
    vector<employee> employees_copy(employees);

    // In <algorithm>, there is stable_sort(), i.e.,
    //   see Josuttis text, Section 11.9 Sorting Algorithms
    // Call stable_sort as follows:
    //   ARG 1: the "begin" iterator of employees_copy
    //   ARG 2: the "end" iterator of employees_copy
    //   ARG 3: pass a less than predicate function/lambda/function object
    //     that defines less than on two employee records, e1 and e2, 
    //     as follows:
    //
    //       e1.name < e2.name
    //
    //     NOTE 1: Writing a lambda is easiest.
    //     NOTE 2: The less than function's arguments' type should be
    //       employee const&.
    stable_sort(employees_copy.begin(), employees_copy.end(), 
      [](employee const& e1, employee const& e2){return e1.name < e2.name;});

    // output data...
    cout << "      BY_NAME: " << employees_copy << endl;
  }
  // the local scope created earlier by { ends with }
  // e.g., employees_copy is now destroyed.


  // stable_sort employees by salary...
  //   ARG 1: the "begin" iterator of employees
  //   ARG 2: the "end" iterator of employees
  //   ARG 3: a predicate function/lambda/function object that defines
  //     the less than of two employees as: e1.salary < e2.salary
   stable_sort(employees.begin(), employees.end(), 
      [](employee const& e1, employee const& e2){return e1.salary < e2.salary;});

  // output data...
  cout << "    BY_SALARY: " << employees << endl;

  // The boss wants to give a 2% pay raise to employees whose salary is 
  // between $20,000 and $30,000! Follow the instructions in the comments
  // below to do this...

  // In <algorithm> there is an algorithm called find_if() which we'll call
  // twice storing the results in two variables: low_end and upper_end:
  //
  //   * low_end: the first find_if() will determine the FIRST iterator 
  //       position where e.salary >= 20000.0 && e.salary <= 30000.0 is true,
  //       OR, the end iterator position if there was no match, and,
  //       NOTE: The first find_if() call must start from the "beginning"
  //             iterator!
  //
  //   * upper_end: the second call will determine the ONE-PAST-THE-LAST 
  //       iterator position where e.salary >= 20000.0 && e.salary <= 30000.0
  //       is true, OR, the end iterator position if there was no match.
  //       NOTE: The second find_if() call must start from the low_end
  //             iterator!
  //
  // HINTS: 
  //   * Do this as TWO variable declarations.
  //   * Each variable declaration can either be:
  //       auto low_end = /* find_if() code */;
  //       auto upper_end = /* find_if() code */;
  //     OR:
  //       vector<employee>::iterator low_end = /* find_if() code */;
  //       vector<employee>::iterator upper_end = /* find_if() code */;
  //     but, clearly, auto is much simpler.
  //   * Read more about find_if() in the Josuttis text and/or 
  //     cppreference.com.
  auto low_end = find_if(employees.begin(), employees.end(), [](employee emp){return (emp.salary >= 20000 && emp.salary <= 30000);});
  auto upper_end = find_if(low_end, employees.end(), [](employee emp){return (emp.salary < 20000 && emp.salary > 30000);});

  // Now that you have the half-open range [low_end,upper_end)
  // you can increase all employees' salaries in that range!
  // In exactly two lines of code, write a for loop as follows:
  //   FOR "INIT" CLAUSE: Use auto to declare a variable i whose
  //     initial value is low_end.
  //   FOR "TEST" CLAUSE: Keep looping while i != upper_end.
  //   FOR "INCREMENT" CLAUSE: Write ++i.
  //     NOTE: DON'T WRITE i++!!
  //   FOR LOOP BODY: Since the iterator i points to an employee,
  //     you can access an employee struct's salary member
  //     with i->salary. Thus, in a single line of code, use the *= 
  //     operator to increase the employee's salary by 2%.
  for (auto i = low_end; i != upper_end; ++i)
    i->salary *= 1.02;

  // output data...
  cout << "SALARY_ADJUST: " << employees << endl;

  // Finally, know you can use <algorithm>s, etc. where the
  // "beginning" and "end" iterators are not the container's
  // beginning and end iterators!
  //
  // Since you already have [low_end,upper_end), write the
  // single line of code to REVERSE all container data in the
  // range [low_end,upper_end) by calling <algorithm>'s
  // reverse() function.
  //
  // See the Josuttis text and/or cppreference.com for the
  // definition of reverse. (Use the two argument version.)
  reverse(low_end, upper_end);

  // output data...
  cout << "AFTER_REVERSE: " << employees << endl;
}

