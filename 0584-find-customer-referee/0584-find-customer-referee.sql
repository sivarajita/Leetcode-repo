# Write your MySQL query statement below
select name as name from Customer 
where referee_id is null or referee_id!=2;