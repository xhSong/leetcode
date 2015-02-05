class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
        int n = dungeon.size(), m = dungeon[0].size();
        for (int j = m - 2; j >= 0; --j) dungeon[n - 1][j] += min(0, dungeon[n - 1][j + 1]);
        for (int i = n - 2; i >= 0; --i) {
            dungeon[i][m - 1] += min(0, dungeon[i + 1][m - 1]);
            for (int j = m - 2; j >= 0; --j) {
                dungeon[i][j] += min(0, max(dungeon[i + 1][j], dungeon[i][j + 1]));
            }
        }
        return max(-dungeon[0][0], 0) + 1;
    }
};