class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int p = 0, n = words.size();
        while (p < n) {
            int q = p + 1, tot_len = words[p].size();
            while (q < n && tot_len + words[q].size() + q - p <= L) {
                tot_len += words[q++].size();
            }
            int cntword = q - p;
            int cntspace = cntword - 1;
            string line = words[p];
            if (cntword == 1) {
                for (int i = 0; i < L - words[p].size(); ++i) {
                    line.push_back(' ');
                }
            } else if (q < n) {
                for (int i = 1; i <= cntspace; ++i) {
                    int space = (L - tot_len) / cntspace + (i <= (L - tot_len) % cntspace);
                    for (int j = 0; j < space; ++j) {
                        line.push_back(' ');
                    }
                    for (int j = 0; j < words[p + i].size(); ++j) {
                        line.push_back(words[p + i][j]);
                    }
                }
            } else {
                for (int i = p + 1; i < q; ++i) {
                    line.push_back(' ');
                    for (int j = 0; j < words[i].size(); ++j) {
                        line.push_back(words[i][j]);
                    }
                }
                int left = L - line.size();
                for (int i = 0; i < left; ++i) {
                    line.push_back(' ');
                }
            }
            ans.push_back(line);
            p = q;
        }
        return ans;
    }
};