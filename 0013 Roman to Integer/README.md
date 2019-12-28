## 算法1 

**(模拟)O(n)**

1. 定义将单一字符映射到数字；
2. 从前往后扫描，如果 ```s[i + 1] > s[i]```，那么累加 ```s[i + 1] - s[i]```即可，并将```i```多往后移动一位;否则直接累加```s[i]```;

```CPP
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char, int> words;
        words['I'] = 1; words['V'] = 5;
        words['X'] = 10; words['L'] = 50; 
        words['C'] = 100; words['D'] = 500;
        words['M'] = 1000;
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && words[s[i + 1]] > words[s[i]]) {
                ans += words[s[i + 1]] - words[s[i]];
                i++;
            }
            else
                ans += words[s[i]];
        }
        return ans;
    }
};
```
