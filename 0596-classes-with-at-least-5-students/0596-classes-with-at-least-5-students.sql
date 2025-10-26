# Write your MySQL query statement below
select class as class from Courses 
Group by class
having count(class) >=5;
