#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, h = nums.size()-1;
        while(m <= h){
            if(nums[m] == 1)
                m ++;
            else if(nums[m] == 0){
                swap(nums[l], nums[m]);
                m ++, l ++;
            }
            else{
                swap(nums[h], nums[m]);
                h --;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> vec{2,0,2,1,1,0};
    s.sortColors(vec);
    for (int n : vec)
        cout << n << " ";

    return 0;
}