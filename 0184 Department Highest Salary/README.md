## 算法1


因为 Employee 表包含 Salary 和 DepartmentId 字段，我们可以以此在部门内查询最高工资。
```SQL
SELECT
    DepartmentId, MAX(Salary)
FROM
    Employee
GROUP BY DepartmentId;
```

然后，我们可以把表 Employee 和 Department 连接，再在这张临时表里用 IN 语句查询部门名字和工资的关系。
```SQL
SELECT D.Name as Department, E.Name as Employee, E.Salary as Salary
FROM Employee E, Department D 
where E.DepartmentId = D.Id
AND (DepartmentId, Salary) IN 
    (SELECT
        DepartmentId, MAX(Salary)
    FROM
        Employee
    GROUP BY DepartmentId)
```