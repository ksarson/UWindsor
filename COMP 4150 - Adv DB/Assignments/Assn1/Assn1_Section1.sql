#Q1
select emp_name, salary from employees;

#Q2
select distinct job_name from employees;

#Q3
select emp_name, salary*1.15 as "Salary Increase" from employees;

#Q4
select emp_name from employees where dep_id != 2001;

#Q5
select avg(salary) as "Analyst Avg Salary" from employees where job_name = 'ANALYST';

#Q6
select * from employees where commission > salary;

#Q7
select emp_name from employees where salary*1.25 > 3000;

#Q8
select emp_name, job_name from employees where manager_id is null;

#Q9
select emp_id, emp_name, salary, extract(year from current_date) - extract(year from hire_date) as "Years Expierence" 
from employees where salary/30 > 100;

#Q10
select emp_id, emp_name, salary, job_name from employees 
where salary*12 < 34000 and salary > commission and commission is not null and job_name = 'SALESMAN' and dep_id = 3001;

#Q11
select grade, emp_name, dep_id, salary from employees left join salary_grade on (grade!=4) where (dep_id = 1001 or dep_id = 3001) 
and hire_date < cast('1992-12-31' as date) and (employees.salary>=salary_grade.min_salary and employees.salary<=salary_grade.max_salary);

#Q12
select emp_name, salary from employees left join salary_grade on (grade is not null) where emp_name = 'FRANK' and salary=salary_grade.max_salary; 

#Q13
select emp_name, dep_location from employees left join department on (department.dep_id = employees.dep_id) where (salary >= 2000 and salary <= 5000) 
and extract(year from hire_date) = 1991 and (dep_location = 'SYDNEY' or dep_location = 'MELBOURNE');

#Q14
select emp_name, dep_location, grade from employees left join department on (department.dep_id = employees.dep_id) 
left join salary_grade on (grade>=3 and grade<=5) 
where (dep_location = 'MELBOURNE' or dep_location = 'PERTH')and dep_name = 'MARKETING' and 
((extract(year from current_date) - extract(year from hire_date)) > 5) and 
(employees.salary>=salary_grade.min_salary and employees.salary<=salary_grade.max_salary);

#Q15
select emp_name, grade from employees left join salary_grade on (grade=4) 
where (employees.salary>=salary_grade.min_salary and employees.salary<=salary_grade.max_salary)