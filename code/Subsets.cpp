class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> now;
        sort(S.begin(), S.end());
        _gen(S, 0, now, ans);
        return ans;
    }
private:
    void _gen(vector<int> &S, int k, vector<int> &now, vector<vector<int> > &ans, bool c = true) {
        if (k == S.size()) {
            ans.push_back(now);
            return ;
        }
        _gen(S, k + 1, now, ans, false);
        if (c == false && S[k - 1] == S[k]) return;
        now.push_back(S[k]);
        _gen(S, k + 1, now, ans, true);
        now.pop_back();
    }
};