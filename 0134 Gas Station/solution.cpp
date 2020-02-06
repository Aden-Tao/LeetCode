#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 如果总的gas> 总的cost那么肯定存在一个地点可以， 就是从第一个gas[]>cost[]
        int total_gas = 0, total_cost = 0, tank = 0, begin = 0;
        
        for(int i = 0; i < gas.size(); i ++){
            total_gas += gas[i];
            total_cost += cost[i];
            
            tank = tank + gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                begin = i+1;
            }
        }
        
        return (total_gas < total_cost) ? -1 : begin;
    }
};

int main(){
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}