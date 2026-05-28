# Write your MySQL query statement below
select customer_id,count(Visits.visit_id) as count_no_trans
from Visits
left join Transactions
ON Visits.visit_id = Transactions.visit_id
WHERE Transactions.transaction_id IS NULL
group by customer_id;