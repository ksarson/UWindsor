insert into musician values(111111111, 'Majid Peters', '4747 Oakwood Dr', 1113331112);
insert into musician values(222222222, 'Steven Markel', '1231 Berry Ave', 2221113332);
insert into musician values(333333333, 'Melanie Good', '423 Walker Rd', 1231235555);
insert into musician values(444444444, 'John Doe', '5431 Hefty Lane', 6751231231);


insert into Instrument values('Flute', 'C-Flat');
insert into instrument values('Trumpet', 'E-Flat');
insert into instrument values('Guitar', 'A-Minor');
insert into instrument values('Drums', 'B-Minor');


insert into Song values('Hello World', '21 Savage');
insert into Song values('Happy All', '21 Savage');
insert into Song values('Love Sosa', 'Chief Keef');
insert into Song values('Ball For Me', 'Post Malone');


insert into album values('111', 'Recovery', '08-Jun-04', 'CD');
insert into album values('222', 'Revival', '09-Sep-09', 'CD');
insert into album values('333', 'Welcome', '03-Apr-14', 'CD');


insert into play values(111111111, 'Drums');
insert into Play values(111111111, 'Flute');
insert into Play values(111111111, 'Guitar');
insert into Play values(222222222, 'Trumpet');
insert into play values(333333333, 'Guitar');


insert into contains values('111', 'Hello World');
insert into contains values('111', 'Happy All');
insert into contains values('222', 'Love Sosa');
insert into contains values('333', 'Ball For Me');


insert into Performs values(111111111, 'Hello World');
insert into Performs values(222222222, 'Love Sosa');
insert into Performs values(333333333, 'Ball For Me');
insert into performs values(333333333, 'Hello World');


insert into produces values(111111111, 111);
insert into produces values(222222222, 222);
insert into produces values(333333333, 333);

COMMIT;
