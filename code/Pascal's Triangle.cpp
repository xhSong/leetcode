class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >pascal;
        if (numRows == 0) return pascal;
        pascal.push_back(vector<int> (1, 1));
        for (int i = 1; i < numRows; ++i) {
            vector<int> &up = pascal[i - 1], line;
            line.push_back(1);
            for (int i = 1; i < up.size(); ++i) {
                line.push_back(up[i - 1] + up[i]);
            }
            line.push_back(1);
            pascal.push_back(line);
        }
        return pascal;
    }
};