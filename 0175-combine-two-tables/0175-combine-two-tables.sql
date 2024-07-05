# Write your MySQL query statement below
select firstName,lastName,city ,state from Person p left JOIN Address  a on p.personId=a.personId;