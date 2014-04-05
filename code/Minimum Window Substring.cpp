class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> cnt(256, 0);
        int cnttype = 0;
        for (int i = 0; i < T.size(); ++i) {
            if (cnt[T[i]] == 0) {
                -- cnttype;
            }
            -- cnt[T[i]];
        }
        int ansx = 0, anslen = S.size() + 1, x = 0;
        for (int i = 0; i < S.size(); ++i) {
            ++ cnt[S[i]];
            if (cnt[S[i]] == 0) {
                ++ cnttype;
            }
            while(cnttype == 0) {
                if (cnt[S[x]] == 0) {
                    -- cnttype;
                }
                if (anslen > i - x) {
                    ansx = x;
                    anslen = i - x + 1;
                }
                -- cnt[S[x++]];
            }
        }
        if (anslen == S.size() + 1) return "";
        return S.substr(ansx, anslen);
    }
};