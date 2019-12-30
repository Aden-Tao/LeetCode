#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; i ++)
        {
            if (!i || nums[i] != nums[pos - 1])
                nums[pos ++] = nums[i];
        }
        return pos;
    }
};

int main(){
    vector<int> vec{0,0,1,1,1,2,2,3,3,4};
    assert(Solution().removeDuplicates(vec) == 5);
    
    return 0;
}