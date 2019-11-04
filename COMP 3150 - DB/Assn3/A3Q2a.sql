select M.MNAME, M.PHONE 
from Musician M, Produces P, Song S, Contains C 
where M.ssn = p.SSN and P.AID = C.aid and 
C.Stitle = S.stitle and s.author = 'Chief Keef';
