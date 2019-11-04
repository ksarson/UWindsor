select S.stitle, s.author, a.atitle, a.copyrightdate, count(*)
from Song S, Album A, Contains c, Performs P
where s.stitle = c.stitle and a.aid = c.aid and P.stitle = S.stitle 
group by s.stitle, s.author, a.atitle, a.copyrightdate;

