CREATE TABLE department (
  dep_id INTEGER,
  dep_name VARCHAR(20),
  dep_location VARCHAR(15)
);

CREATE TABLE salary_grade (
  grade INTEGER,
  min_salary INTEGER,
  max_salary INTEGER
);

CREATE TABLE employees(
  emp_id INTEGER,
  emp_name VARCHAR2(15),
  job_name VARCHAR2(10),
  manager_id INTEGER,
  hire_date DATE,
  salary DECIMAL(10,2),
  commission DECIMAL(7,2),
  dep_id INTEGER
);