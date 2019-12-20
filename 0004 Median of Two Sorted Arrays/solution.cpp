#include <bits/stdc++.h>
using namespace std;

 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int len=nums1.size()+nums2.size();
        int cutL=0, cutR=nums1.size()-1;
        int cut1, cut2;
        
        while(true){
            cut1 = cutL+(cutR-cutL)/2;
            cut2 = len/2-cut1;
            int L1 = (cut1==0) ? INT_MIN : nums1[cut1-1];
            int L2 = (cut2==0) ? INT_MIN : nums2[cut2-1];
            int R1 = (cut1==nums1.size()) ? INT_MAX : nums1[cut1];
            int R2 = (cut2==nums2.size()) ? INT_MAX : nums2[cut2];
            if(L1>R2) // to left
                cutR = cut1-1;
            else if(L2>R1) //to right
                cutL = cut1+1;
            else{
                if(len%2==0) // even , choose (k-1, k)/2
                    return (max(L1, L2) + min(R1, R2))/2.0;
                else  //odd
                    return min(R1, R2);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> n1{1,3}, n2{2};
    assert( (s.findMedianSortedArrays(n1, n2) == 2.0) );
    return 0;
}