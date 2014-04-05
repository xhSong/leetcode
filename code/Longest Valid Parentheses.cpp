class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (stk.size() >= 2 && s[stk.top()] == '(' && s[i] == ')') {
                stk.pop();
                ans = max(ans, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        return ans;
    }
};