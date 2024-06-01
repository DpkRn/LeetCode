# Write your MySQL query statement below
select product_name, year, price from Product a right outer join Sales b on a.product_id=b.product_id;