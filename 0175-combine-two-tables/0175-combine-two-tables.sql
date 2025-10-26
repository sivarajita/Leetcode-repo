# Write your MySQL query statement below
select lastname,firstname,city,state from Person as p
left join Address as a on p.personid=a.personid;
