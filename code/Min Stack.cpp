class MinStack {
public:
    void push(int x) {
        if (stk.size() == 0 || x <= minvalue) {
            stk.push(minvalue);
            minvalue = x;
        }
        stk.push(x);
    }
    
    void pop() {
        int popvalue = stk.top();
        stk.pop();
        if (popvalue == minvalue) {
            minvalue = stk.top();
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minvalue;
    }
    
private:
    stack<int> stk;
    int minvalue;
};