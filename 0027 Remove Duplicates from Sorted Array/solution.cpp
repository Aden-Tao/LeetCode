#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[k++] = nums[i];
        return k;
    }
};

int main(){
    vector<int> vec{3,2,2,3};
    assert(Solution().removeElement(vec, 3) == 2);
    return 0;
}