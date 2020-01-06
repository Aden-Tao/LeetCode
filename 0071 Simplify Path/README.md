## 算法1

**(模拟)*O(n)***

模拟这个过程，用 res 记录当前的路径位置：

1. 如果遇到 ".."，则返回上级目录；
2. 如果遇到 "."或多余的斜杠，则不做任何处理：
3. 其它情况，表示进入某个子目录，我们在 res 后面补上新路径即可；

```CPP
class Solution {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') path += '/';
        string res, s;
        for (auto &c : path)
        {
            if (res.empty()) res += c;
            else if (c == '/')
            {
                if (s == "..")
                {
                    if (res.size() > 1)
                    {
                        res.pop_back();
                        while (res.back() != '/') res.pop_back();
                    }
                }
                else if (s != "" && s != ".")
                {
                    res += s + '/';
                }
                s = "";
            }
            else
            {
                s += c;
            }
        }
        if (res.size() > 1) res.pop_back();
        return res;
    }
};
```

```Python
class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for token in path.split('/'):
            if token in ['', '.']:
                pass
            elif token == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(token)
        return '/' + '/'.join(stack)
```