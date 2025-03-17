# Write your MySQL query statement below
-- (select v.visit_id,v.customer_id as c,t.amount from visits as v left join transactions as t on v.visit_id=t.visit_id)

select customer_id,count(customer_id) as count_no_trans from (select v.visit_id,v.customer_id as customer_id,t.amount as a from visits as v left join transactions as t on v.visit_id=t.visit_id where t.transaction_id is null)as subquery group by customer_id order by count_no_trans asc
