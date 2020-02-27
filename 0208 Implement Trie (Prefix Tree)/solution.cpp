#include "iostream"
#include "string"
using namespace std;

class Trie {
private:
    struct Node
    {
        bool is_end;
        Node *son[26];
        Node()
        {
            is_end = false;
            for (int i = 0; i < 26; i++)
                son[i] = NULL;
        }
    };
    
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (char c: word)
        {
            int u = c - 'a';
            if (p->son[u] == NULL)
                p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (char c: word)
        {
            int u = c - 'a';
            if (p->son[u] == NULL)
                return false;
            p = p->son[u];
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (char c: prefix)
        {
            int u = c - 'a';
            if (p->son[u] == NULL)
                return false;
            p = p->son[u];
        }
        return true;
    }
};

int main(){
    Trie *trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple") << endl;   // 返回 true    
    cout << trie->search("app") << endl;     // 返回 false
    cout << trie->startsWith("app") << endl; // 返回 true
    trie->insert("app");   
    cout << trie->search("app") << endl;     // 返回 true

    return 0;
}
