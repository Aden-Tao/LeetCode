## 算法1

**(图的遍历，DFS)*O(n)***

用 map 去存储已经生成的节点, 对于一个节点，递归的访问他的邻居，并且复制他的邻居节点。需要注意：如果这个节点之前被访问过，那就不访问。

```CPP
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if(mp.find(node) == mp.end()){
            mp[node] = new Node(node -> val);
            for(auto neigh: node -> neighbors){
                mp[node] -> neighbors.push_back(cloneGraph(neigh));
            }
        }
        return mp[node];
    }
};
```