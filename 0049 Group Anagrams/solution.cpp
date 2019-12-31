#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for (string s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto item: mp)
            res.push_back(item.second);
        return res;
    }
};

int main(){
    vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto r : Solution().groupAnagrams(vec))
    {
        for (auto a : r)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}