#include "iostream"
#include "string"

using std::string;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ms[256] = {0}, mt[256] = {0}, n = s.size();
        
        for(int i = 0; i<n; i++){
            if(ms[s[i]] != mt[t[i]])
                return false;
            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }
        
        return true;
    }
};

int main(){
    std::cout << Solution().isIsomorphic("egg", "add") << std::endl;
    std::cout << Solution().isIsomorphic("foo", "bar") << std::endl;
    return 0;
}