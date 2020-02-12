## 算法1

```SQL
SELECT A.Name as Employee
FROM Employee A
INNER JOIN Employee B
on A.ManagerId = B.Id
AND A.Salary > B.Salary
```