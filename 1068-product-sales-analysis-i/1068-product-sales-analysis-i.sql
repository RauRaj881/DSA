# Write your MySQL query statement below
select product_name,year,price
from Sales
left join Product
on Sales.Product_id=Product.Product_id;