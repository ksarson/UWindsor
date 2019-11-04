create table Musician(
SSN Number(9) not null,
Mname varchar2(20), 
Maddr varchar2(20), 
phone Number(10), 
primary key(SSN));

create table Instrument(
iname varchar(20) not null, 
musickey varchar(15), 
primary key(iname));

create table Album(
Aid varchar(15) not null, 
atitle varchar(20), 
copyrightdate DATE, 
format varchar(20),
primary key(aid));

create table song(
stitle varchar(30) not null, 
author varchar(25), 
primary key(stitle));

create table Play(
SSN Number(9) not null, 
iname varchar2(20) not null, 
primary key(SSN, iname),
foreign key(SSN) references musician(SSN), 
foreign key(iname) references instrument(iname));

create table Contains(
Aid varchar(15) not null, 
stitle varchar(30) not null, 
primary key(Aid, stitle),
foreign key (aid) references album(aid), 
foreign key(stitle) references song(stitle));

create table Performs(
SSN number(9) not null, 
stitle varchar(30) not null,
primary key(SSN, stitle), 
foreign key(SSN) references Musician(SSN), 
foreign key(stitle) references song(stitle));

create table produces(SSN number(9) not null, 
aid varchar(15) not null, 
primary key(ssn , aid),
foreign key(ssn) references musician(ssn), 
foreign key(aid) references album(aid));

COMMIT;