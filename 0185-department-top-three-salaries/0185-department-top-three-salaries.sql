# Write your MySQL query statement below
select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
from(
    select 
        e.*,
        DENSE_RANK() OVER (
            partition by departmentId
            order by salary desc
        ) as rnk
    from Employee e
)e
join Department d
    on e.departmentId = d.id
where e.rnk <= 3;