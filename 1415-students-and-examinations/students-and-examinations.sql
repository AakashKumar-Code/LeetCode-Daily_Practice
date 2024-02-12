# Write your MySQL query statement below


select t.student_id, t.student_name, t.subject_name, COALESCE(COUNT(e.student_id), 0) as attended_exams
from
(select s.student_id, s.student_name, sub.subject_name
from Students as s
cross join Subjects as sub)as t
left join Examinations as e
on t.student_id=e.student_id and t.subject_name=e.subject_name
group by t.student_name, t.subject_name
order by t.student_id, t.subject_name;