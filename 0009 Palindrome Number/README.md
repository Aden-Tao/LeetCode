## 算法1

 **(循环)O(1)**

 反转一半数字防止溢出,我们只需先计算出后一半的逆序值，再判断是否和前一半相等即可。

 ```CPP
 class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x && x % 10 == 0) return false;
        int s = 0;
        while (s <= x)
        {
            s = s * 10 + x % 10;
            if (s == x || s == x / 10) return true; // 分别处理整数长度是奇数或者偶数的情况
            x /= 10;
        }
        return false;
    }
};
 ```