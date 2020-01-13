#Q1
drop table emp_temp;

create table emp_temp as
  select emp_id, emp_name, dep_id, salary from employees;

declare
    cursor employee_cur is
      select emp_id, salary from emp_temp
      where dep_id = 50
      for update;
      incr_sal number;

begin
    for employee_rec in employee_cur loop
        incr_sal := .15;
        update emp_temp
        set salary = salary+salary*incr_sal
        where current of employee_cur;
    end loop;
end;

#Q2
declare
  cursor cur_mgr is
      select emp_name, d.dep_name from employees e
      inner join department d on d.dep_id = e.dep_id
      where e.job_name = 'MANAGER';
      v_mgr cur_mgr%rowtype;

begin
  open cur_mgr;
    loop
      fetch cur_mgr into v_mgr;
      exit when cur_mgr%notfound;
      dbms_output.put_line(v_mgr.emp_name || ' :: ' || v_mgr.dep_name);
    end loop;
  close cur_mgr;
end;

#Q3
declare
    cursor department_cur is
      select d.dep_id dept_id, dep_name, dep_location, e.emp_name man_name from department d
      join employees e on (e.dep_id = d.dep_id and e.job_name = 'MANAGER');
      employee_name employees.emp_name%type;
      emp_max_salary employees.salary%type;

begin
  dbms_output.put_line('--------------------------------------------------------------------------------');
  dbms_output.put_line(rpad('Name of the Department', 25) || rpad('Manager', 15) || 
                      rpad('Head Office', 15) || 'Highest Earner');
  dbms_output.put_line('--------------------------------------------------------------------------------');
  for emp_dept_cur in department_cur loop
    begin
      select max(salary) into emp_max_salary from employees
      where dep_id = emp_dept_cur.dept_id;
      if emp_max_salary is null then
        employee_name := '...';
      else
        select emp_name into employee_name from employees
        where dep_id = emp_dept_cur.dept_id and salary = emp_max_salary;
      end if;
      dbms_output.put_line(rpad(emp_dept_cur.dep_name, 25) || rpad(emp_dept_cur.man_name, 15) || 
                          rpad(emp_dept_cur.dep_location, 15) || employee_name);
      exception
      when too_many_rows then
        dbms_output.put_line(rpad(emp_dept_cur.dep_name, 25) || rpad(emp_dept_cur.man_name, 15) || 
                            rpad(emp_dept_cur.dep_location, 15) || ' - More than one employee');
    end;
  end loop;
end; 

#Q4
declare
    cursor emp_job_cur is
      select distinct emp_name, job_name from employees;
      count_jobs number(2);

begin
    dbms_output.put_line('-------------------------------------------------');  
    dbms_output.put_line(rpad('Employee Name', 15) || 'Number of Jobs');
    dbms_output.put_line('-------------------------------------------------');
    for employee_list in emp_job_cur loop
      count_jobs :=
      case
      when employee_list.job_name = 'ANALYST' then
        2
      when employee_list.job_name = 'PRESIDENT' then
        2
      else
        1
      end;
      dbms_output.put_line(Rpad(employee_list.emp_name, 15) ||  count_jobs);
    end loop;
end;  

#Q5
drop table emp_temp;
create table emp_temp as
  select * from employees;

declare
  cursor employees_cur is
    select emp_id, emp_name, trunc(months_between(sysdate, hire_date)/12) expr from emp_temp;
  incre_per number(2);

begin
  dbms_output.put_line(rpad('Employee ID', 15) || rpad('Name', 25) || 'increment %');
  dbms_output.put_line('-----------------------------------------------------------');
  for store_emp_rec in employees_cur loop
    incre_per :=
    case
    when store_emp_rec.expr > 27 then
      15
    when store_emp_rec.expr > 25 then
      10
    else
      5
    end;
    update emp_temp
    set salary = salary+(salary*incre_per/100)
    where emp_id = store_emp_rec.emp_id;
      dbms_output.put_line(rpad(store_emp_rec.emp_id,15) || rpad(store_emp_rec.emp_name,25) || incre_per); 
  end loop;
end;

#Q6
declare
    cursor employees_cur is
      select emp_id, emp_name, job_name, hire_date from employees;
begin
  dbms_output.put_line(rpad('Employee ID', 15) || rpad('First Name', 15) || rpad('Job Title', 15) || 'First date');
  dbms_output.put_line('-----------------------------------------------------------------------------------------');
  for emp_sal_rec in employees_cur loop
    dbms_output.put_line(rpad(emp_sal_rec.emp_id, 15) || rpad(emp_sal_rec.emp_name, 15)
                        || rpad(emp_sal_rec.job_name, 15) || rpad(emp_sal_rec.hire_date, 15));
  end loop;
end;

#Q7
declare
    cursor department_cur is
      select dep_id, dep_name, max(salary) maxsalary from employees
      join department using (dep_id)
      group by dep_id, dep_name;
    emp_first_name employees.emp_name%type;

begin
  dbms_output.put_line('------------------------------------------------------------');
  dbms_output.put_line(rpad('Name of the Department', 25) || rpad('Highest Salary', 25));
  dbms_output.put_line('------------------------------------------------------------');
  for emp_dept_cur in department_cur loop
    begin
      select emp_name into emp_first_name from employees
      where dep_id = emp_dept_cur.dep_id and salary = emp_dept_cur.maxsalary;
      dbms_output.put_line(rpad(emp_dept_cur.dep_name, 25) || rpad(emp_first_name, 25));
      exception
      when too_many_rows then
        dbms_output.put_line(rpad(emp_dept_cur.dep_name, 25) || ' - More than one employee');
    end;
  end loop;
end; 

#Q8
declare
  cursor emp_cur (def_job_name varchar2 := 'MANAGER') is
    select d.dep_name, e.emp_name manager, d.dep_location from department d, employees e
    where d.dep_id = e.dep_id and e.job_name = def_job_name
    order by d.dep_id;
  procedure dep_cur is
    depname department.dep_name%type;
    dep_mgr employees.emp_name%type;
    dep_in_city department.dep_location%type;

  begin
    loop
      fetch emp_cur into depname, dep_mgr, dep_in_city;
      exit when emp_cur%notfound;
      dbms_output.put_line(rpad(depname, 25) || rpad(dep_mgr, 15) || dep_in_city);
    end loop;
  end dep_cur;
 
begin
  dbms_output.put_line('DEPARTMENTS AT :');
  dbms_output.put_line('----------------------------');
  dbms_output.put_line(rpad('Department', 25) || rpad('Manager', 15) || 'City');
  dbms_output.put_line('-------------------------------------------------------');
  open emp_cur();
  dep_cur; 
  close emp_cur;
end;

#Q9
declare
  cursor employees_cur is
    select emp_id, emp_name, job_name , hire_date from employees;

begin
  dbms_output.put_line( rpad('Employee Name', 15) || rpad('Job Title', 15)|| 'Starting Date');
  dbms_output.put_line('----------------------------------------------');
  for employee_rec in employees_cur loop
    dbms_output.put_line(rpad(employee_rec.emp_name, 15) ||
                        rpad(employee_rec.job_name, 15) || employee_rec.hire_date);
  end loop;
end; 

#Q10
declare
  cursor cur_for_dep is
    select d.dep_id, d.dep_name, d.dep_location, e.emp_name from department d
    left join employees e on (e.dep_id = d.dep_id)
    where job_name = 'MANAGER';
    
    function count_for_emp (p_deptid number)
    return number
    is
      count_of_emp number(3);
    begin
      select count(*) into count_of_emp from employees
      where dep_id = p_deptid;
      return count_of_emp;
    end;
    
begin
  dbms_output.put_line(rpad('Department Name', 20) || rpad('Department Head', 20)
                      || rpad('Head office', 20) || 'Number of Employees');
  dbms_output.put_line('----------------------------------------------------------------------------------');
  for rows_of_dep in cur_for_dep loop
    dbms_output.put_line(rpad(rows_of_dep.dep_name, 20) || rpad(rows_of_dep.emp_name, 20)
                        || rpad(rows_of_dep.dep_location, 20) || count_for_emp(rows_of_dep.dep_id));
  end loop;
end;