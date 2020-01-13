--1
--Select all of the courses that a certain student is taking
select c.name from course c
join sectrion_records ser on ser.course_id = C.course_id
join student_records sr on sr.section_rec = ser.section_rec
join student s on s.student_id = sr.student_id where s.student_id = 100000001;

--2
--Select all of the courses that a certain professor is teaching
select c.course_name from course c, professor p, sectrion_records s where
c.course_id = s.course_id and p.professor_id = s.professor_id and
p.first_name = 'BOBBY';

--3
--Select all of the courses where a student gets an A
select c.course_name from course c
join sectrion_records se on se.course_id = c.course_id
join student_records sr on sr.section_rec = se.section_rec
join student s on s.student_id = sr.student_id
where student_id = 100000002 and sr.grade >= 80;

--4 
--Select all students taking a specific course
select s.student_id, s.first_name, s.last_name from student s
join student_records sr on sr.student_id = s.student_id
join sectrion_records se on se.section_rec = sr.section_rec
join course c on s.course_id = se.course_id
where c.course_id = 'COMP1050';

--5
--Select the room that a course is being taught in
select r.building, r.room_code from room r
join sectrion_records sr on sr.room_id = r.room_id
join course c on c.course_id = sr.course_id
where c.course_id = 'COMP2080';

--6 
--Select all students currently taking a course with a certain professor
select s.student_id, s.first_name, s.last_name from student s
join student_records sr on sr.student_id = s.student_id
join sectrion_records se on se.section_rec = sr.section_rec
join professor p on se.professor_id = p.professor_id
where p.professor_id = 9001;

--7 
--Select the department names of all students
select s.first_name, s.last_name, d.department_name from Student s
join department d on d.department_id = s.department_id;

--8
--Select all courses are offered by a department
select c.course_id, c.course_name from course c
join department d on d.department_id = c.department_id
where d.department_id = 'COMPUTER SCIENCE';

--9
--Select all students on the honour roll
select s.student_id, s.first_name, s.last_name from student s where s.gpa >= 80.0;

--10
--Update grades to add a 5% curve to the grades of all students in a certain section of a course
declare
	cursor c1 for
	select s.student_id from student s
	join student_records sr on sr.student_id = s.student_id
	where sr.section_rec = '1234' for update;
	exit_loop boolean;
	continue handler for not found set exit_loop = true;

begin
	open c1;
	curve_loop: loop
		update student_records
		set grade := grade * 1.05
		where current of c1;

		if exit_loop then
        	close c1;
        	leave curve_loop;
     	end if;
	end loop curve_loop;
end;

--11
--Delete a student from a course who voluntarily dropped it online
declare
	create or replace trigger delete_student_warning
	before delete on student_records

	declare
		begin
			-- execute query if they say yes
		end;

		cursor c1 for
		select sr.record_id from student_records sr
		join sectrion_records se on se.section_rec = sr.section_rec
		join course c on c.course_id = se.course_id
		where sr.student_id = 100000001 
		and c.course_id = 'COMP1050' for update;
		exit_loop boolean;
		continue handler for not found set exit_loop = true;

begin
	open c1;
	vw_loop: loop
		delete from student_records where current of c;
		if exit_loop then
        	close c1;
        	leave vw_loop;
     	end if;
	end loop vw_loop;
end;

--12
--Update a student’s major
declare
	create procedure update_major(id number(9), major_name varchar2(30))
		begin
			update student
			set major = major_name
			where student_id = id;	
		end;
begin
	update_major(100000001, 'Business');
end;

--13
--Update a student’s section of a course
declare
	cursor c1 is 
	select sr.student_id, sr.section_rec, se.section_id
	from student_records sr
	join section_records se on se.section_rec = sr.section_rec for update;

begin
	
	for c in c1 loop
		update section_records
		set section_id = $new_id
		where current of c;
	end loop;

end;

--14
--Update the professor who is teaching a course section
declare
begin

	update section_records 
	set professor_id = 9001
	where course_id = 'COMP1050'
	and section_id =  01

end;

--15
--Calculate the average of a course section
declare
	cursor c1 is
	select sr.record_id, sr.grade from student_records sr
	join section_records se on se.section_rec = sr.section_rec
	where se.course_id = 'COMP2260' and se.section_id = 1 for update;

	grade_total number;
	average number;

begin
	
	for c in c1 loop
		grade_total := grade_total + c.grade;
	end loop;

	open c1;

	average := grade_total / c1%ROWCOUNT; 

	-- do something with average

	close c1;
end;