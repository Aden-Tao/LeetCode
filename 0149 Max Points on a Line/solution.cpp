#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty())  return 0;
        int res = 0;

        for (int i = 0; i < points.size(); i ++)
        {
            unordered_map<long double, int> map;
            int duplicates = 0, verticals = 1;

            for (int j = i + 1; j < points.size(); j ++)
                if (points[i][0] == points[j][0])
                {
                    verticals ++;
                    if (points[i][1] == points[j][1])
                        duplicates ++;
                }
                
            for (int j = i + 1; j < points.size(); j ++)
                if (points[i][0] != points[j][0])
                {
                    long double slope = (long double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    if (map[slope] == 0) map[slope] = 2;
                    else    map[slope] ++;
                    res = max(res, map[slope] + duplicates);
                }
            res = max(res, verticals);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> points{{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
    cout << Solution().maxPoints(points) << endl;
    return 0;
}