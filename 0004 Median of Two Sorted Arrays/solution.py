#!python3

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        m, n = len(nums1), len(nums2)
        imin, imax = 0, m 
        
        while imin <= imax:
            i = (imin+imax)//2     #nums1的切分点
            j = (m+n+1) // 2 - i   #nums2的切分点
            
            if i<m and nums2[j-1] > nums1[i]: #i 太小
                imin = i + 1
            elif i>0 and nums1[i-1] > nums2[j]: #i 太大
                imax = i - 1
            else:
                if i==0: max_of_left = nums2[j-1]
                elif j==0: max_of_left = nums1[i-1]
                else:    max_of_left = max(nums1[i-1], nums2[j-1]);
                
                if (m + n) % 2 == 1:   #奇数
                    return max_of_left
                
                if i == m:   min_of_right = nums2[j]
                elif j == n: min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j]);
                
                return (max_of_left + min_of_right) / 2.0

if __name__ == "__main__":
    n1, n2 = [1, 2], [3, 4]
    print(Solution().findMedianSortedArrays(n1, n2) == 2.5)