(
select u.name AS results
from Users u
join MovieRating r
on u.user_id=r.user_id
group by u.user_id ,u.name
order by count(*) DESC,u.name
LIMIT 1
)
UNION ALL

(
select m.title as results 
from movies m
join MovieRating r
on m.movie_id=r.movie_id
where  created_at BETWEEN '2020-02-01' AND '2020-02-29'
group by m.movie_id,m.title
order by avg(rating) DESC,m.title
LIMIT 1
);