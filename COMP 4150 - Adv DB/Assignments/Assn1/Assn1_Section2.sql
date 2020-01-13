#Q1-----------------------------------------
declare
  c varchar2(8 char);

begin
  c := 'abc  ';
  dbms_output.put_line(c||'*');
end;

#Q2-----------------------------------------
drop table test;
create table test (col1 char(5));
 
declare
  testVar varchar2(5 char) := 'abc ';

begin
  insert into test(col1) values(testVar);
end;

#Q3-----------------------------------------
declare
  charac char(15 char);
  varcharac varchar2(15 char);

begin
  charac := 'char ';
  varcharac  := 'varchar2 ';
  dbms_output.put_line('*'||charac||'*');
  dbms_output.put_line('*'||varcharac||'*');
end;

#Q4-----------------------------------------
drop procedure boolean_value;
create procedure boolean_value (bl boolean) authid definer as
begin
  dbms_output.put_line (
    case
      when bl is null then 'Unknown'
      when bl then 'Yes'
      when not bl then 'No'
    end
  );
end;
/

begin
  boolean_value(null);
  boolean_value(false);
  boolean_value(true);
end;

#Q5-----------------------------------------
declare
  incentive number(8,2);
  
begin
  select salary into incentive from employees where emp_id = 69000;
  dbms_output.put_line('Before 12% adjustment incentive = '||incentive);
  incentive := incentive * 1.12;
  dbms_output.put_line('After 12% adjustment incentive = '||incentive);
end;

#Q6-----------------------------------------
declare
	num_small number := 9;
	num_large number := 1;
	num_temp number;

begin
	if num_small > num_large 
	then
		num_temp := num_small;
		num_small := num_large;
		num_large := num_temp;
	end if;

	dbms_output.put_line ('num_small = '||num_small);
	dbms_output.put_line ('num_large = '||num_large);
end;

#Q7-----------------------------------------
declare
	testDate date := to_date('&new_dt', 'DD-MON-YYYY');
	get_day varchar2(15);

begin
	get_day := rtrim(to_char(testDate, 'day'));
	if get_day in ('saturday', 'sunday') then
		dbms_output.put_line(get_day||' is on the weekend');
	else
		dbms_output.put_line (get_day||' is not on the weekend');
	end if;
end;

#Q8-----------------------------------------
declare
    grade char(1);

begin
    grade := '&new_grade';
    if grade = 'A' then
      dbms_output.put_line('Your Grade is >=80%');
    elsif grade = 'B' then
      dbms_output.put_line('Your Grade is between 70-79%');
    elsif grade = 'C' then
      dbms_output.put_line('Your Grade is between 60-69%');
    elsif grade = 'D' then
      dbms_output.put_line('Your Grade is between 50-59%');
    elsif grade = 'F' then
      dbms_output.put_line('Your Grade is <50%');
    else
      dbms_output.Put_line('No such grade in the list.');
    end if;
end;

#Q9-----------------------------------------
declare
    grade char(1);

begin
    grade := '&new_grade';
    case grade
    when 'A' then
      dbms_output.put_line('Your Grade is >=80%');
    when 'B' then
      dbms_output.put_line('Your Grade is between 70-79%');
    when 'C' then
      dbms_output.put_line('Your Grade is between 60-69%');
    when 'D' then
      dbms_output.put_line('Your Grade is between 50-59%');
    when 'F' then
      dbms_output.put_line('Your Grade is <50%');
    else
      dbms_output.Put_line('No such grade in the list.');
    end case;
end;

#Q10----------------------------------------
drop table emp_temp;
create table emp_temp (
  emp_id number,
  emp_email varchar2(40)
);
 
declare
  number_of_emp number;

begin
  select count(emp_id) into number_of_emp from employees;
  for i in 1..number_of_emp loop
    insert into emp_temp (emp_id, emp_email)
    values(i, 'nothing');
  end loop;
end;