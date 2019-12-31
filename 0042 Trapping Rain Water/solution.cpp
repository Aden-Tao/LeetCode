#include <bits/stdc++.h>
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        if (n == 0)  return res;
        
        vector<int> left(n), right(n);
        left[0] = height[0];
        for (int i = 1; i < n; i ++)
            left[i] = std::max(left[i - 1], height[i]);
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --)
            right[i] = std::max(right[i + 1], height[i]);
        
        for (int i = 0; i < n; i ++)
            res += std::min(left[i], right[i]) - height[i];
        return res;
    }
};

int main(){
    vector<int> vec{0,1,0,2,1,0,1,3,2,1,2,1};
    assert(Solution().trap(vec) == 6);
    return 0;
}
