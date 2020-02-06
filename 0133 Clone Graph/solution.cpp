#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

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

void printUndirectedGraph(Node *node) {
    std::ostringstream out;
    std::unordered_map<int, std::unordered_set<int>> map{{0, std::unordered_set<int>()}};
    std::deque<Node*> cache;
    cache.push_back(node);
    do {
        std::sort(cache.begin(), cache.end(),[](Node* n1, Node* n2){
            return n1->val < n2->val;
        });
        Node *node = cache.front(); cache.pop_front();
        out << node->val;
        auto found = map.find(node->val);
        for (Node* neighbor : node->neighbors) {
            if (map.find(neighbor->val) == map.end()) cache.push_back(neighbor);
            if (found != map.end()) {
                std::unordered_set<int> &exist = found->second;
                if (exist.find(neighbor->val) == exist.end()) out << "," << neighbor->val;
            }
            map[neighbor->val].emplace(node->val);
        }
        out << "#";
    } while (!cache.empty());
    std::string out_str = out.str();
    std::cout << out_str.substr(0, out_str.size()-1) << std::endl;
}

int main() {
    Solution s;
    
    Node node1(1);
    Node node2(2);
    // Node node3(3);
    // Node node4(4);

    node1.neighbors.push_back(&node2);
    // node1.neighbors.push_back(&node4);
    node2.neighbors.push_back(&node1);
    // node2.neighbors.push_back(&node3);
    // node3.neighbors.push_back(&node2);
    // node3.neighbors.push_back(&node4);
    // node4.neighbors.push_back(&node1);
    // node4.neighbors.push_back(&node3);
    
    printUndirectedGraph(&node1);
    Node *node = s.cloneGraph(&node1);
    printUndirectedGraph(node);
}
