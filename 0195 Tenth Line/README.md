## 算法1

awk 'NR == 10' file.txt NR在awk中指行号

sed -n 10p file.txt -n表示只输出匹配行，p表示Print

tail -n+10 file.txt|head -1 tail -n +10表示从第10行开始输出

```Bash
awk '{if (NR==10) print $0}' file.txt
```