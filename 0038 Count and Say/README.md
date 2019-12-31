## 算法1

**(模拟)**

* 直接按照从 ```2``` 到 ```n```的顺序生成字符串，即每次找连续相同的数字段，合并

```CPP
class Solution {
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 1; i < n; i++)
        {
            string t = "";
            for (int j = 0; j < s.size(); j++)
            {
                int cnt = 1;
                while (j + 1 < s.size() && s[j] == s[j + 1])
                {
                    cnt ++, j++;
                }
                
                t += to_string(cnt) + s[j];
            }
            s = t;
        }
        return s;
    }
};
```

```Python
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for _ in range(n - 1):
            s = ''.join(str(len(list(group))) + digit
                    for digit, group in itertools.groupby(s))
        return s
```