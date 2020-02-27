## 算法1

**(拓扑排序)*O(n + m)***

1. 将先修关系构成一张图，由每个数对的第二个数字向第一个数字连边;
2. 首先将所有入度为0的点进队，准备拓扑排序;
3. 宽搜过程中，将当前结点所关联的结点的入度减1；若发现新的入度为0的结点，则将其进队;
4. 最后如果遍历了所有结点，则说明可以满足要求；否则，先修关系存在环;

```CPP
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i ++)
        {
            in_degree[prerequisites[i][0]] ++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<bool> vis(numCourses, false);
        
        for (int i = 0; i < numCourses; i ++)
            if (in_degree[i] == 0)
                q.push(i);
        
        while (!q.empty())
        {
            int sta = q.front();
            q.pop();
            vis[sta] = true;
            for (int i = 0; i < graph[sta].size(); i ++)
            {
                in_degree[graph[sta][i]] --;
                if (in_degree[graph[sta][i]] == 0)
                    q.push(graph[sta][i]);
            }
        }
        
        for (int i = 0; i < numCourses; i ++)
            if (vis[i] == false)
                return false;
        return true;
    }
};
```