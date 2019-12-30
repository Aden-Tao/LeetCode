#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), cnt = 0, head = 0;
        int res = 0;
        for (int i = 0; i < n; i ++)
        {
            if (s[i] == '(')  cnt ++;
            else  cnt --;
            if (cnt < 0)
            {
                cnt = 0;
                head = i + 1;
            }
            else if (cnt == 0)
                res = max(res, i - head + 1);
        }
        head = n - 1, cnt = 0;
        for (int i = n - 1; i >= 0; i --)
        {
            if (s[i] == ')')  cnt ++;
            else  cnt --;
            if (cnt < 0)
            {
                cnt = 0;
                head = i - 1;
            }
            else if (cnt == 0)
                res = max(res, head - i + 1);
        }
        return res;
    }
};

int main(){
    string s = ")()())";
    assert( Solution().longestValidParentheses(s) == 4 );
    return 0;
}