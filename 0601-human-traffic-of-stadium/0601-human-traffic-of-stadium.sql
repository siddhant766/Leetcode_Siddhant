# Write your MySQL query statement below
WITH cte AS(
    select *,
        id - ROW_NUMBER() OVER (ORDER By id) AS grp
    From Stadium
    Where people >=100
)
Select id,visit_date,people
FROM cte
WHERE grp IN (
    SELECT grp
    FROM cte
    GROUP BY grp
    HAVING COUNT(*) >= 3
)

order by visit_date;