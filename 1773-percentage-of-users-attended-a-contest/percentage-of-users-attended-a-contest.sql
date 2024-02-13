# Write your MySQL query statement below


select r.contest_id, 
coalesce(round(count(u.user_id)*100/(select count(distinct user_id) from Users), 2), 0) 
as percentage
from Users as u
right join Register as r
on u.user_id=r.user_id
group by r.contest_id
order by percentage desc, contest_id;
