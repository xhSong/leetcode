class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line(rowIndex + 1, 1);
        long long c = 1;
        for (int i = 1; i < rowIndex; ++i) {
            c = c * (rowIndex - i + 1) / i;
            line[i] = c;
        }
        return line;
    }
};