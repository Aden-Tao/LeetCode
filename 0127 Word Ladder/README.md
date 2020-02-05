## 算法1

**(最短路,BFS)*O($n^2$L)***

将单词看做点，如果两个单词可以相互转化，则在相应的点之间连一条无向边。那问题就变成了求从起点到终点的最短路。

由于边权都相等，所以可以用BFS求最短路。

时间复杂度分析：BFS的过程中每个点会遍历一次，每次遍历时需要枚举所有节点，判断是否存在边，总共需要判断 $n^2$ 次，假设单词长度是 L，则每次判断时还需要 O(L) 的计算量，所以总时间复杂度是 O($n^2$L)。

```CPP
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))  return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int level = 0, len = endWord.size();
        
        while (q.size())
        {
            ++level;
            for (int i = q.size(); i > 0; i --)
            {
                string t = q.front();
                q.pop();
                for (int i = 0; i < len; i ++)
                {
                    char c = t[i];
                    for (int j = 'a'; j <= 'z'; j ++)
                    {
                        t[i] = j;
                        if (t == endWord) return level + 1;
                        if (!dict.count(t))  continue;
                        q.push(t);
                        dict.erase(t);
                    }
                    t[i] = c;
                }
            }
        }
        return 0;
    }
};
```