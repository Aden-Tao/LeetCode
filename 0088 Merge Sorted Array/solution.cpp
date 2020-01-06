#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while(j >= 0 && i >= 0)
            nums1[k--] =  nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    for (int n : nums1)
        cout << n << " ";
    return 0;
}