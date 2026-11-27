# Write your MySQL query statement below
select p.unique_id , e.name
from Employees e
left join EmployeeUNI p
on e.id = p.id ;