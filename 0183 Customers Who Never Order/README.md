## 算法1

使用子查询和 NOT IN 子句

```SQL
SELECT Name as Customers
FROM Customers
WHERE Customers.Id 
NOT IN (SELECT CustomerId 
        FROM Orders)
```

```SQL
#使用左连接快一点
SELECT C.Name as Customers
FROM Customers C
LEFT JOIN Orders O
ON C.Id = O.CustomerId
WHERE O.Id IS NULL
```