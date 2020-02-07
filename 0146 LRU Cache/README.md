## 算法1

**(链表，哈希) *O(1)***

1. key-value 的增删改查显然需要用一个哈希表来实现，这道题困难地方在于删除时，如何判断需要删除的元素;
2. 我们使用一个双向链表来实现：初始时链表中有两个 dummy 结点，分别是 head 和 tail；新插入一个元素，将其插入到 tail 的前，然后在哈希表中记录下新元素的结点地址;
3. 遇到要删除的时候，删除 head 之后的那个结点，同时释放哈希表的内存；
4. 遇到 get 操作或者 set 操作时，通过哈希表找到这个结点的地址，然后将其取出，放到 tail 前，然后修改哈希表的值；

```CPP
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```