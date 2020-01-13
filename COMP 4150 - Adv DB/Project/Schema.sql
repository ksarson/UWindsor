CREATE TABLE `Student` (
  `student_id` int PRIMARY KEY,
  `first_name` varchar(255),
  `last_name` varchar(255),
  `email` varchar(255),
  `major` varchar(255),
  `gpa` int,
  `department_id` int
);

CREATE TABLE `Professor` (
  `professor_id` int PRIMARY KEY,
  `first_name` varchar(255),
  `last_name` varchar(255),
  `email` varchar(255),
  `department_id` int
);

CREATE TABLE `Course` (
  `course_id` int PRIMARY KEY,
  `course_name` varchar(255),
  `description` varchar(255),
  `department_id` int
);

CREATE TABLE `Student_Records` (
  `record_id` int PRIMARY KEY,
  `student_id` int,
  `section_rec` int,
  `grade` int,
  `status` varchar(255),
  `year` int,
  `semester` varchar(255)
);

CREATE TABLE `Room` (
  `room_id` int PRIMARY KEY,
  `room_num` int,
  `building` varchar(255),
  `capacity` int
);

CREATE TABLE `Department` (
  `department_id` int PRIMARY KEY,
  `department_name` varchar(255)
);

CREATE TABLE `Section_Records` (
  `section_id` int,
  `section_rec` int PRIMARY KEY,
  `course_id` int,
  `professor_id` int,
  `room_id` int,
  `day_of_week` varchar(255),
  `start_time` timestamp,
  `end_time` timestamp
);

ALTER TABLE `Professor` ADD FOREIGN KEY (`department_id`) REFERENCES `Department` (`department_id`);

ALTER TABLE `Section_Records` ADD FOREIGN KEY (`room_id`) REFERENCES `Room` (`room_id`);

ALTER TABLE `Section_Records` ADD FOREIGN KEY (`professor_id`) REFERENCES `Professor` (`professor_id`);

ALTER TABLE `Section_Records` ADD FOREIGN KEY (`course_id`) REFERENCES `Course` (`course_id`);

ALTER TABLE `Course` ADD FOREIGN KEY (`department_id`) REFERENCES `Department` (`department_id`);

ALTER TABLE `Student` ADD FOREIGN KEY (`department_id`) REFERENCES `Department` (`department_id`);

ALTER TABLE `Student_Records` ADD FOREIGN KEY (`student_id`) REFERENCES `Student` (`student_id`);

ALTER TABLE `Student_Records` ADD FOREIGN KEY (`section_rec`) REFERENCES `Section_Records` (`section_rec`);

ALTER TABLE `Student_Records` ADD FOREIGN KEY (`record_id`) REFERENCES `Section_Records` (`section_id`);
