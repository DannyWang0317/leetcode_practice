#include <iostream>
#include <vector>
using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    vector<vector<int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = getMin();
        if(st.empty() || val < min_val){
            min_val = val;
        }
        st.push_back({val, min_val});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.empty()? -1: st.back()[0];
    }
    
    int getMin() {
        return st.empty()? -1: st.back()[1];
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(0);
    obj->push(-3);

    cout << "getMin: " << obj->getMin() << endl;
    obj->pop();

    cout << "top: " << obj->top() << endl;
    cout << "getMin: " << obj->getMin() << endl;

    return 0;
}
