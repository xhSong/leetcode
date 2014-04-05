class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int k = 2; k <= n; ++k) {
            string read;
            ans.push_back('e');
            int cnt = 1;
            for (int i = 1; i < ans.size(); ++i) {
                if (ans[i - 1] == ans[i]) {
                    ++ cnt;
                } else {
                    char cs[32];
                    itoa(cnt, cs);
                    read += string(cs);
                    read.push_back(ans[i - 1]);
                    cnt = 1;
                }
            }
            ans = read;
        }
        return ans;
    }
private:
    int itoa(int n, char s[]) {
        if (n < 10) {
            s[0] = n + '0';
            s[1] = 0;
            return 1;
        }
        int len = itoa(n / 10, s);
        s[len++] = n % 10 + '0';
        s[len] = 0;
        return len;
    }
};