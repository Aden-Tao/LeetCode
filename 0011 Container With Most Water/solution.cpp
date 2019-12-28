#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            res = max(res, 
                min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> vec{1,8,6,2,5,4,8,3,7};
    assert(s.maxArea(vec) == 49);
    return 0;
}