# Write your MySQL query statement below
select En.unique_id,E.name from Employees as e left join EmployeeUNI as en on E.id=En.id;