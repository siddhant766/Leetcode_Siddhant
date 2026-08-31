# Write your MySQL query statement below
with daily_counts as (
    select 
        user_id,
        action_date,
        action,
        count(*) over(
            PARTITION by user_id, action_date
        ) as cnt
        from activity
),

valid_days as (
    select 
        user_id,
        action_date,
        action
    from daily_counts
    where cnt = 1
),
streaks AS (
    select 
        user_id,
        action,
        action_date,
        DATE_SUB(
            action_date,
            INTERVAL ROW_NUMBER() over (
                partition by user_id, action
                order by action_date
            )day
        )as grp
        from valid_days
),
summary as (
    select 
        user_id,
        action,
        count(*) as streak_length,
        MIN(action_date) as start_date,
        MAX(action_date) as end_date
    from streaks
    group by user_id , action, grp
    having count(*) >= 5
),
ranked as (
    select*,
        ROW_NUMBER() over(
            partition by user_id
            order by streak_length DESC
        )AS rn
        FROM summary
)

select 
    user_id,
    action,
    streak_length,
    start_date,
    end_date
from ranked
where rn =1
order by streak_length desc, user_id asc;








