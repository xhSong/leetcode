class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        select.clear();
        _gen(k, n, 0);
        return  ans;
    }
private:
    void _gen(int k, int n, int last) {
        if (select.size() == k) {
            ans.push_back(select);
            return ;
        }
        for (int i = last + 1; i <= n; ++i) {
            select.push_back(i);
            _gen(k, n, i);
            select.pop_back();
        }
    }
    vector<int> select;
    vector<vector<int> > ans;
};