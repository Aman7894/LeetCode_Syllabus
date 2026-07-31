# Write your MySQL query statement below
select U.user_id as buyer_id, U.join_date, count(O.order_id) as orders_in_2019 from 
Users U left  join Orders O on
O.buyer_id=U.user_id
and YEAR(O.order_date) =2019
group by U.user_id , U.join_date
