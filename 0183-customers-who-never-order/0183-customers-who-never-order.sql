# Write your MySQL query statement below
select  name as Customers
from Customers As c
left join Orders AS o
on c.id=o.customerId
where o.customerId IS NULL;
