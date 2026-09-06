# Write your MySQL query statement below
select contest_id,
round((count(r.contest_id)/( select count(*) from Users))*100,2) as percentage
from Users as u
join Register as r
on u.user_id=r.user_id
group by contest_id
order by percentage desc,contest_id asc;

