## 算法1

**(拓扑排序)*O(n + m)***

1. 类似 [Course Schedule](../0207%20Course%20Schedule/README.md);
2. 拓扑排序时用的队列的进队顺序就是一个可行的输出方案;

```CPP
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i ++)
        {
            in_degree[prerequisites[i][0]] ++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<bool> vis(numCourses, false);
        vector<int> res;
        for (int i = 0; i < numCourses; i ++)
            if (in_degree[i] == 0)
                q.push(i);
        
        while (!q.empty())
        {
            int sta = q.front();
            q.pop();
            vis[sta] = true;
            res.push_back(sta);
            for (int i = 0; i < graph[sta].size(); i ++)
            {
                in_degree[graph[sta][i]] --;
                if (in_degree[graph[sta][i]] == 0)
                    q.push(graph[sta][i]);
            }
        }
        
        for (int i = 0; i < numCourses; i ++)
            if (vis[i] == false)
                return vector<int>{};
        return res;
    }
};
```