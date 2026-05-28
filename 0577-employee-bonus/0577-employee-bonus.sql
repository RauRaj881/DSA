# Write your MySQL query statement below
select name,bonus
from Employee
left join Bonus
on bonus.empId=Employee.empId
where Bonus.bonus<1000 or Bonus.bonus is null;