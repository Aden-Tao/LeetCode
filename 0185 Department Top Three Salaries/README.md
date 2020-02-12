## 算法1

公司里前 3 高的薪水意味着有不超过 3 个工资比这些值大。

```SQL
select e1.Name as 'Employee', e1.Salary
from Employee e1
where 3 >
(
    select count(distinct e2.Salary)
    from Employee e2
    where e2.Salary > e1.Salary
)
```
在这个代码里，我们统计了有多少人的工资比 e1.Salary 高，所以样例的输出应该如下所示

| Employee | Salary |
|----------|--------|
| Henry    | 80000  |
| Max      | 90000  |
| Randy    | 85000  |

然后，我们需要把表 Employee 和表 Department 连接来获得部门信息。

```SQL
select d.name department, e1.name employee, e1.salary
from employee e1
inner join department d 
on e1.departmentId = d.id
where 3 > (
		select count(distinct e2.salary)
		from employee e2
		where e2.salary > e1.salary 
		and e2.departmentId = d.id  
	)
order by d.name, salary desc
```