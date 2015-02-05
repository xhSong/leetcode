class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int> &num) {
        vector<string> numstr(num.size());
        for (size_t i = 0; i < num.size(); ++i) {
            numstr[i] = std::to_string(num[i]);
        }
        std::sort(numstr.begin(), numstr.end(), cmp);
        string result;
        size_t i = 0;
        while (i < numstr.size() && numstr[i] == "0") ++i;
        for (; i < numstr.size(); ++i) {
            result += numstr[i];
        }
        return result == ""? "0": result;
    }
};
