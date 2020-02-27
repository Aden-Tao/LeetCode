#include "iostream"
#include "vector"
#include "queue"
using namespace std;

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

int main(){
    vector<vector<int>> graph{{1, 0}};
    cout << Solution().canFinish(2, graph) << endl;

    graph = {{1, 0}, {0,1}};
    cout << Solution().canFinish(2, graph) << endl;

    return 0;
}