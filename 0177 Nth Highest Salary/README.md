## 算法1

本题涉及的知识点：<br>
1. MySQL里函数的定义语句;<br>
2. MySQL里设置变量及给变量赋值语句;<br>
3. MySQL里IFNULL语句使用;<br>
4. 有排序语句要考虑是否需要去重;<br>
5. MySQL里limit语句的使用;
 
```SQL
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT 
      IFNULL(
          (SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT 1 OFFSET M), 
      NULL)
  );
END
```