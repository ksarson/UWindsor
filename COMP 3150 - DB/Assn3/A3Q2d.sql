select S.stitle, M.mname, a.atitle
from Song S, Musician M, Album A, Contains C, Performs P
where S.stitle = C.stitle and C.aid = A.aid and 
p.stitle = s.stitle and m.ssn = p.ssn;

