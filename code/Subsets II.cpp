class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        ans.clear();
        now.clear();
        sort(S.begin(), S.end());
        _gen(S, 0, true);
        return ans;
    }
private:
    void _gen(vector<int> &S, int k, bool last) {
        if (k == S.size()) {
            ans.push_back(now);
            return ;
        }
        
        _gen(S, k + 1, false);
        
        if (!(last == false && S[k] == S[k - 1])) {
            now.push_back(S[k]);
            _gen(S, k + 1, true);
            now.pop_back();
        }
    }
    vector<vector<int> > ans;
    vector<int> now;
};