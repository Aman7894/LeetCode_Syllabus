# Write your MySQL query statement below
select name, bonus
from Employee as e
left join Bonus as b
on e.empId=b.empId 
where b.bonus<1000
OR b.bonus IS NULL;

