## 算法1

xargs 分割字符串 -n 1 表示每行输出一个 可以加 -d 指定分割符

要使用uniq统计词频需要被统计文本相同字符前后在一起，所以先排序 uniq -c 表示同时输出出现次数

sort -nr 其中-n表示把数字当做真正的数字处理(当数字被当做字符串处理，会出现11比2小的情况)


```bash
cat words.txt | xargs -n 1 | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
```