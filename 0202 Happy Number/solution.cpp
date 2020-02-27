#include "iostream"
#include "unordered_set"
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (true)
        {
            int t = 0;
            while (n)
            {
                t += (n % 10) * (n % 10);
                n /= 10;
            }

            if (t == 1)
                return true;
            else if (st.find(t) != st.end())
                return false;
            else
                st.insert(t);
            n = t;
        }
    }
};

int main(){

    cout << Solution().isHappy(19) << endl;
    cout << Solution().isHappy(22) << endl;
    return 0;
}