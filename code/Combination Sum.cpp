class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        sort(candidates.rbegin(), candidates.rend());
        int c[n], m = 0;
        c[m++] = candidates[0];
        for (int i = 1; i < n; ++i) {
            if (candidates[i] != candidates[i - 1]) c[m++] = candidates[i];
        }
        ans.clear();
        select.clear();
        _gen(c, m, target);
        return ans;
    }
private:
    void _gen(int c[], int n, int target) {
        if (n == 0) {
            if(target == 0) {
                vector<int> onec(select.rbegin(), select.rend());
                ans.push_back(onec);
            }
            return ;
        }
        int times = 0;
        
        while(c[0] * ++times <= target) {
            select.push_back(c[0]);
            _gen(c + 1, n - 1, target - c[0] * times);
        }
        
        for (int i = 1; i < times; ++i) {
            select.pop_back();
        }
        _gen(c + 1, n - 1, target);
    }
    vector<vector<int> >  ans;
    vector<int> select;
};
