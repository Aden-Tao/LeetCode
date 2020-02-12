## 算法1

MySQL 使用 DATEDIFF 来比较两个日期类型的值。

因此，我们可以通过将 weather 与自身相结合，并使用 DATEDIFF() 函数。

[DATEDIFF(expr1,expr2)](https://dev.mysql.com/doc/refman/5.7/en/date-and-time-functions.html#function_datediff)

```SQL
select w2.id
from weather w1, weather w2
where datediff(w2.recordDate, w1.recordDate) = 1
and w1.Temperature < w2.Temperatur
```