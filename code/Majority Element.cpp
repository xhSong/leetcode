class Solution {
public:
    int majorityElement(vector<int> &num) {
        std::stack<int> stk;
        for (size_t i = 0; i < num.size(); ++i) {
            if (!stk.empty() && stk.top() != num[i]) {
                stk.pop();
            } else {
                stk.push(num[i]);
            }
        }
        return stk.top();
    }
};