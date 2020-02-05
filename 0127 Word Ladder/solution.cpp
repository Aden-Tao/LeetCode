#include "bits/stdc++.h"
using namespace std;

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

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}