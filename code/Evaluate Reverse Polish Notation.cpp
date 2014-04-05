class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        int a, b;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                getab(numbers, a, b);
                numbers.push(a + b);
            } else if (tokens[i] == "-") {
                getab(numbers, a, b);
                numbers.push(a - b);
            } else  if (tokens[i] == "*") {
                getab(numbers, a, b);
                numbers.push(a * b);
            } else  if (tokens[i] == "/") {
                getab(numbers, a, b);
                numbers.push(a / b);
            } else {
                numbers.push(atoi(tokens[i].c_str()));
            }
        }
        return numbers.top();
    }
private:
    void getab(stack<int> &numbers, int &a, int &b) {
        b = numbers.top();
        numbers.pop();
        a = numbers.top();
        numbers.pop();
    }
};