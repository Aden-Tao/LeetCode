## 算法1

考点 LEFT JOIN, RIGHT JOIN 以及 在使用LEFT JOIN时，on和where区别:<br>
数据库连接两张或多张表来返回记录时，都会生成一张中间的临时表，然后再将这张临时表返回给用户。在用时LEFT JOIN时，on 和 where条件的区别如下：
1. on 条件在生成临时表时使用的条件，不管on中条件是否为真，都会返回左表中的记录
2. where 条件是在临时表生成后，再对临时表进行过滤条件。这时已经没有LEFT JOIN的含义了（必须返回左表的记录），条件不为真的就全部过滤掉

```SQL
SELECT FirstName, LastName, City, State
FROM Person
LEFT JOIN Address on Person.PersonId = Address.PersonId
```