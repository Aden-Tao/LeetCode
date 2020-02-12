## 算法1

考察自连接

```SQL
#对于每个Score,都统计不相同的大于等于该Score的个数
SELECT Score,
       (SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) as RANK
FROM Scores s
ORDER BY Score DESC
```

```SQL
#直接内连接，注意要将相同Id聚合
SELECT A.Score, COUNT(DISTINCT B.Score) as Rank  -- 注意按题目要求去重复值
FROM Scores A INNER JOIN Scores B
ON A.Score <= B.Score  -- 表b中有x个非重复值大于等于表a当前值，则表a当前成绩排名为x
GROUP BY A.Id  -- 由于成绩即使重复也要显示，故通过id分组
ORDER BY A.Score DESC
```