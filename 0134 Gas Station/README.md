## 算法1

**(一次遍历)*O(n)***

车能开完全程需要满足两个条件：

1. 车从i站能开到i+1;<br>
2. 所有站里的油总量要 >= 车子的总耗油量;<br>

为什么应该将起始站点设为k+1？<br>
因为 k -> k+1 站耗油太大，0 -> k站剩余油量都是不为负的，每减少一站，就少了一些剩余油量。所以如果从k前面的站点作为起始站，剩余油量不可能冲过 k+1 站。<br>

为什么如果k+1->end全部可以正常通行，且rest>=0就可以说明车子从k+1站点出发可以开完全程？<br>
因为，起始点将当前路径分为A、B两部分。其中，必然有(1)A部分剩余油量<0。(2)B部分剩余油量>0。所以，无论多少个站，都可以抽象为两个站点（A、B）。(1)从B站加满油出发，(2)开往A站，车加油，(3)再开回B站的过程。

重点：B剩余的油>=A缺少的总油。必然可以推出，B剩余的油>=A站点的每个子站点缺少的油。

```CPP
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
```