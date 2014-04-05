#define maxn 100000

struct _TreeNode {
    _TreeNode * c[26], *fail;
    int Lid;
    _TreeNode() {
        init();
    }
    void init() {
        for (int i = 0; i < 26; ++i) {
            c[i] = NULL;
        }
        fail = NULL;
        Lid = -1;
    }
}nodes[maxn], *que[maxn];

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        if (S.size() == 0 || L.size() == 0) return ans;
        int len = L[0].size(), n = 0;
        vector<int> cnt(L.size(), 0);
        
        sort(L.begin(), L.end());
        cnt[n++] = 1;
        for (int i = 1; i < L.size(); ++i) {
            if (L[i] == L[n - 1]) {
                ++ cnt[n - 1];
            } else {
                L[n++] = L[i];
                cnt[n - 1] = 1;
            }
        }
        vector<int> f(S.size());
        
        cntnode = 0;
        nodes[cntnode].init();
        _TreeNode *root = &nodes[cntnode++];
        for (int i = 0; i < n; ++i) {
            insert(root, L[i].c_str(), i);
        }
        
        createAC(root);
        
        _TreeNode *pos = root;
        for (int i = 0; i < S.size(); ++i) {
            while (pos != root && pos->c[S[i] - 'a'] == NULL) {
                pos = pos->fail;
                assert(pos != NULL);
            }
            if (pos->c[S[i] - 'a'] != NULL) {
                pos = pos->c[S[i] - 'a'];
            }
            f[i] = pos->Lid;
        }
        
        for (int i = 0; i < len; ++i) {
            vector<int> visted(n, 0);
            int cntL = 0;
            for (int j = i; j < S.size(); j += len) {
                if (f[j] != -1) {
                    ++ visted[f[j]];
                    if (visted[f[j]] == cnt[f[j]]) {
                        ++ cntL;
                    }
                }
                int out = j - len * L.size();
                if (out >= 0 && f[out] != -1) {
                    -- visted[f[out]];
                    if (visted[f[out]] == cnt[f[out]] - 1) {
                        -- cntL;
                    }
                }
                if (cntL == n) {
                    ans.push_back(out + 1);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void insert(_TreeNode *root, const char s[], int Lid) {
        for (int i = 0; s[i]; ++i) {
            int k = s[i] - 'a';
            if (root->c[k] == NULL) {
                nodes[cntnode].init();
                root->c[k] = &nodes[cntnode++];
            }
            root = root->c[k];
        }
        root->Lid = Lid;
    }
    
    void createAC(_TreeNode *root) {
        int left = 0, right = 0;
        que[right++] = root;
        root->fail = root;
        while (left < right) {
            _TreeNode *now = que[left++], *pos;
            for (int i = 0; i < 26; ++i) {
                if (now->c[i] == NULL) continue;
                if (now == root) {
                    now->c[i]->fail = root;
                } else {
                    pos = now->fail;
                    while (pos != root && pos->c[i] == NULL) {
                        pos = pos->fail;
                    }
                    if (pos->c[i] != NULL) {
                        pos = pos->c[i];
                    }
                    now->c[i]->fail = pos;
                }
                que[right++] = now->c[i];
            }
        }
    }
    int cntnode;
};
