## 算法1

**(线性合并)*O(m + n)***

1. 设置```k```指针指向合并后的nums1数组(大小为m + n)的最后一个元素，```i```指向合并前的nums1数组(大小为m)的最后一个元素，```j```指向nums2数组(大小为n)的最后一个元素;
2. 比较```i```指向的值和```j```指向的值，将大的值挪进nums1[k];
3. ```k```指针往前挪，```i```或者```j```指针也相应往前挪;
4. 循环以上步骤直到```i = 0```或```j = 0```;
5. 若```j >= 0```,将nums2数组剩余的元素挪进nums1;


```CPP
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
```
