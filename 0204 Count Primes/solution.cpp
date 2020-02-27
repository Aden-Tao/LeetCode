#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, false);
        int cnt = 0;
        
        for(int i=2; i<n; i++){
            if(prime[i] == false) 
                cnt++;
            for(int j=2; j*i<n; j++)
                prime[j*i] = true;
    }
        return cnt;
    }
};

int main(){

    cout << Solution().countPrimes(10) << endl;
    return 0;
}