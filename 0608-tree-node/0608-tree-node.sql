# Write your MySQL query statement below
select id,
case when p_id IS NULL then 'Root'
 when id in (select p_id from Tree
 where p_id is NOT NULL)
 then 'Inner'
 else 'Leaf'
 end as type
 from tree; 
