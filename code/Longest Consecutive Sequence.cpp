class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hashtable;
        vector<pair<int, int>> linked(num.size(), pair<int, int>(-1, -1));
        for (int i = 0; i < num.size(); ++i) {
            hashtable[num[i]] = int(i);
        }
        for (int i = 0; i < num.size(); ++i) {
            if (hashtable.find(num[i] - 1) != hashtable.end()) {
                linked[i].first = hashtable[num[i] - 1];
            }
            if (hashtable.find(num[i] + 1) != hashtable.end()) {
                linked[i].second = hashtable[num[i] + 1];
            }
        }
        int result = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (linked[i].first == -1) {
                int counter = 0;
                for (int pos = i; pos != -1; pos = linked[pos].second) {
                    ++ counter;
                }
                result = max(result, counter);
            }
        }
        return result;
    }
};