# Write your MySQL query statement below
# Write your MySQL query statement below
select  Distinct class 
from Courses
group by class
Having Count(student) >=5;