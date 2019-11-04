select A.copyrightdate, A.format
from Album A, Contains C 
where A.AID = C.AID having count(*) > 1
group by a.copyrightdate, a.format;

