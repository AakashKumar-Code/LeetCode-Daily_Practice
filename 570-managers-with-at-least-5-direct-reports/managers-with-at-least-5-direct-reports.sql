# Write your MySQL query statement below
select emp.name
from
(select t.managerId
from
(select e.managerId, count(*) as cnt
from employee as e
group by e.managerId) as t
where cnt>=5) as temp, Employee as emp
where emp.id=temp.managerId;