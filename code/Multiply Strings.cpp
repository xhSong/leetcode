class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        num1 = string(num1.rbegin(), num1.rend());
        num2 = string(num2.rbegin(), num2.rend());
        
        for (int i = 0; i < num1.size(); ++i) {
            ans = add(ans, multiply(num2, num1[i] - '0'), i);
        }
        while(ans.size() >= 2 && ans[ans.size() - 1] == '0') ans.pop_back();
        return string(ans.rbegin(), ans.rend());
    }
    
private:
    string multiply(string num1, int n2) {
        int c = 0;
        for (int i = 0; i < num1.size(); ++i) {
            c += (num1[i] - '0') * n2;
            num1[i] = c % 10 + '0';
            c /= 10;
        }
        if (c) {
            num1.push_back(c + '0');
        }
        return num1;
    }
    
    string add(string num1, string num2, int pow) {
        string ans;
        int c = 0;
        for (int i = 0, j = -pow; i < num1.size() || j < num2.size(); ++i, ++j) {
            if (i < num1.size()) {
                c += num1[i] - '0';
            }
            if (0 <= j && j < num2.size()) {
                c += num2[j] - '0';
            }
            ans.push_back(c % 10 + '0');
            c /= 10;
        }
        if (c) {
            ans.push_back(c + '0');
        }
        return ans;
    }
};

