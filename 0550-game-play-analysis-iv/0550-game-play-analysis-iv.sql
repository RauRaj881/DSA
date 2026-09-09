# Write your MySQL query statement below
select round(sum(datediff(p2.event_date,p1.event_date)=1)/count(distinct p1.player_id),2)
as fraction
from Activity p1
join Activity p2
on p1.player_id=p2.player_id
WHERE p1.event_date = (
    SELECT MIN(event_date)
    FROM Activity
    WHERE player_id = p1.player_id
);