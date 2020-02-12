## 算法1

说明：HAVING和WHERE的差别<br>

1. 一种理解的方法，WHERE在数据分组前进行过滤，HAVING在数据分组后进行过滤。这是一个重要的区别，WHERE排除的行不包括在分组中。这可能会改变计算值，从而影响HAVING子句中基于这些值过滤掉的分组;

2. HAVING与WHERE非常类似，如果不指定GROUP BY，则大多数DBMS会同等对待它们。不过，要区分一点：使用HAVING时应该结合GROUP BY子句，而WHERE子句用于标准的行级过滤;

```SQL
SELECT Email 
FROM Person
GROUP BY Email
HAVING COUNT(*) > 1
```

```SQL
SELECT
	Email 
FROM
	( 
        SELECT Email, count(*) num FROM Person GROUP BY Email 
        ) AS count_table 
WHERE
	num > 1;
```