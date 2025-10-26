# Write your MySQL query statement below
select 
case when count(num)=1 then num else null end as num from mynumbers 
group by num
order by num desc limit 1;