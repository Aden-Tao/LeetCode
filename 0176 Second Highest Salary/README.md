## 算法1

-- 三个解题要点
1. 高，DESC 排序
2. 第二 LIMIT 位移偏移量加以限制
3. 如果没有值，则返回 null，可以通过临时表或者IFNULL

```SQL
#单纯里面的搜索就可以，但是输不出NULL，所以外面再加一层 
SELECT
(SELECT DISTINCT Salary 
FROM Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1)
as SecondHighestSalary
```

```SQL
SELECT MAX(Salary) as SecondHighestSalary 
FROM Employee 
where Salary < (SELECT MAX(Salary) FROM Employee)
```

```SQL
SELECT
    IFNULL(
        (SELECT DISTINCT Salary 
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
        NULL)
    as SecondHighestSalary

```