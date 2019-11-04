select T.iname, I.musickey, M.mname 
from (select iname from Play having count(*) = 1 group by iname) T, Instrument I, Musician M, Play p
where T.iname = I.iname and M.ssn = P.ssn and I.iname = p.iname;



