#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string chars[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return vector<string>();
        
        vector<string> state(1, "");
        for (auto u : digits)
        {
            vector<string> now;
            for (auto c : chars[u - '2'])
                for (auto s : state)
                    now.push_back(s + c);
            state = now;
        }
        return state;
    }
};

int main(){
    Solution s;
    for (const auto &str : s.letterCombinations("23"))
        cout << str << "\t";

    return 0;
}
