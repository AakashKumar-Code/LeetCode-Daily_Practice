# Write your MySQL query statement below

select t.name, t.bonus
from
(select name, bonus
from Employee as e
left join Bonus as b
on e.empId=b.empId) as t
where t.bonus is NULL
or t.bonus<1000;
