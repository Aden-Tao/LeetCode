## 算法1

* 本题考察的是连续出现，会有同学忽略“连续”二字
* 考察对自关联的灵活应用
* 从题目连续3次成绩相等，判断出“成绩相等”和“学号连续”这2个条件,考察构建“连续学号成绩相等”的思维构建能力


```SQL
SELECT DISTINCT l1.Num as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id = l2.Id - 1
AND   l2.Id = l3.Id - 1
AND   l1.Num = l2.Num
AND   l2.Num = l3.Num
```