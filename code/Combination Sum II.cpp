class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int n = num.size();
        ans.clear();
        select.clear();
        if (n == 0) return ans;
        sort(num.rbegin(), num.rend());
        int c[n];
        for (int i = 0; i < n; ++i) {
            c[i] = num[i];
        }
        _gen(c, 0, n, target);
        return ans;
    }
private:
    void _gen(int c[], int k, int n, int target, bool last = true) {
        if (n == k) {
            if(target == 0) {
                vector<int> onec(select.rbegin(), select.rend());
                ans.push_back(onec);
            }
            return ;
        }
        
        if (!(last == false && c[k] == c[k - 1]) && c[k] <= target) {
            select.push_back(c[k]);
            _gen(c, k + 1, n, target - c[k], true);
            select.pop_back();
        }
        
        _gen(c, k + 1, n, target, false);
    }
    vector<vector<int> >  ans;
    vector<int> select;
};