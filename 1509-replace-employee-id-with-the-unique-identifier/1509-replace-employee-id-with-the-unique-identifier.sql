# Write your MySQL query statement below
select EmployeeUNI.unique_id,E.name from Employees as e left join EmployeeUNI on E.id=EmployeeUNI.id;