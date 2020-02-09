## 算法1

**(字符串)*O(n)***

思想很简单，就是用两个指针分别指向两个字符串向后遍历，找到小数点就停下来，把字符串每个小数点分隔开的数字解析出来进行比较，数字越在前面优先级越高。注意有些容易漏掉的细节，例如当一个字符串结束了，但另一个字符串没有结束，那么结束了的字符串之后的数字就一直是0。


```CPP
class Solution {
public:
    int compareVersion(string v1, string v2) 
    {
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size())
        {
            int x = i, y = j;
            while (x < v1.size() && v1[x] != '.') x++;
            while (y < v2.size() && v2[y] != '.') y++;
            int a = i == x ? 0 : atoi(v1.substr(i, x - i).c_str());
            int b = j == y ? 0 : atoi(v2.substr(j, y - j).c_str());

            if (a > b)  return 1;
            if (a < b)  return -1;
            i = x + 1, j = y + 1;
        }
        return 0;
    }
};
```