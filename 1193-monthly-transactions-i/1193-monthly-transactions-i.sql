# Write your MySQL query statement below
select date_format(trans_date,'%Y-%m') as month,
country,
count(t.id) as trans_count,
sum(t.state='approved') as approved_count,
sum(t.amount) as trans_total_amount,
sum(CASE WHEN t.state = 'approved' THEN t.amount ELSE 0 END) as approved_total_amount
from Transactions as t
group by month,country;
