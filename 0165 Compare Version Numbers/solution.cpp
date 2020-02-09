#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) 
    {
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size())
        {
            int x = i, y = j;
            while (x < v1.size() && v1[x] != '.') x++;
            while (y < v2.size() && v2[y] != '.') y++;
            int a = i == x ? 0 : atoi(v1.substr(i, x - i).c_str());
            int b = j == y ? 0 : atoi(v2.substr(j, y - j).c_str());

            if (a > b)  return 1;
            if (a < b)  return -1;
            i = x + 1, j = y + 1;
        }
        return 0;
    }
};

int main(){
    string version1 = "0.1", version2 = "1.1";
    cout << Solution().compareVersion(version1, version2) << endl;
    return 0;
}