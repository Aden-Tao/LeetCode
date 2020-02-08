#include "bits/stdc++.h"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (s_min.empty())
            s_min.push(x);
        else
            s_min.push(min(x, s_min.top()));
    }
    
    void pop() {
        s.pop();
        s_min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
private:
    stack<int> s, s_min;
};

int main(){
    MinStack *minStack = new MinStack();
    (*minStack).push(-2);
    (*minStack).push(0);
    (*minStack).push(-3);
    cout << (*minStack).getMin() << endl;  // --> 返回 -3.
    (*minStack).pop();
    cout << (*minStack).top() << endl;      //--> 返回 0.
    cout << (*minStack).getMin() << endl;   //--> 返回 -2.
    return 0;
}