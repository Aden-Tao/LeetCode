#include "bits/stdc++.h"
using namespace std;

class LRUCache {
public:
    struct Node
    {
        int key;
        Node *prev, *next;
        Node(int k)
        {
            key = k;
            prev = next = nullptr;
        }
    };
    
    int c, tot;
    Node *head, *tail;
    unordered_map<int, pair<int, Node*>> dic;
    
    LRUCache(int capacity) {
        tot = 0;
        c = capacity;
        Node *t1 = new Node(-1);
        Node *t2 = new Node(-1);
        head = t1;
        tail = t2;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (dic.find(key) == dic.end())
            return -1;
        Node *node = dic[key].second;
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        
        node -> next = tail;
        node -> prev = tail -> prev;
        
        tail -> prev -> next = node;
        tail -> prev = node;
        return dic[key].first;
    }
    
    void put(int key, int value) {
        if (dic.find(key) != dic.end())
        {
            dic[key].first = value;
            Node *node = dic[key].second;
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            
            node -> next = tail;
            node -> prev = tail -> prev;
            
            tail -> prev -> next = node;
            tail -> prev = node;
        }
        else 
        {
            if (tot == c)
            {
                Node *node = head -> next;
                dic.erase(node -> key);
                head -> next = node -> next;
                node -> next -> prev = head;
                delete node;
                tot --;
            }
            Node *node = new Node(key);
            dic[key] = make_pair(value, node);
            node -> next = tail;
            node -> prev = tail -> prev;
            
            tail -> prev -> next = node;
            tail -> prev = node;
            tot ++;
        }
    }
};

int main(){
    LRUCache *cache = new LRUCache(2);/* 缓存容量 */ 

    (*cache).put(1, 1);
    (*cache).put(2, 2);
    cout << (*cache).get(1) << endl;       // 返回  1
    (*cache).put(3, 3);    // 该操作会使得密钥 2 作废
    cout << (*cache).get(2) << endl;       // 返回 -1 (未找到)
    (*cache).put(4, 4);    // 该操作会使得密钥 1 作废
    cout << (*cache).get(1) << endl;       // 返回 -1 (未找到)
    cout << (*cache).get(3) << endl;       // 返回  3
    cout << (*cache).get(4) << endl;       // 返回  4

    return 0;
}