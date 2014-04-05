struct TrieTreeNode {
    int c[26];
    bool visted;
    void reset() {
        for (int i = 0; i < 26; ++i) c[i] = 0;
        visted = false;
    }
}nodes[1000000];

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > que;
        
        TrieInit();
        
        for (unordered_set<string>::iterator pos = dict.begin(); pos != dict.end(); ++ pos) {
            TrieInsert(pos->c_str());
        }
        
        inTrie(start);
        que.push(make_pair(start, 1));
        
        while (!que.empty()) {
            pair<string, int> nowpair = que.front();
            que.pop();
            string &now_str = nowpair.first;
            int now_step = nowpair.second;
            
            if (now_str == end) return now_step;
            
            for (int i = 0; i < now_str.size(); ++i) {
                char oc = now_str[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    now_str[i] = c;
                    if (inTrie(now_str)) {
                        que.push(make_pair(now_str, now_step + 1));
                    }
                }
                now_str[i] = oc;
            }
        }
        return 0;
    }
    
private:
    
    void TrieInit() {
        nodes[0].reset();
        cntnodes = 1;
    }
    void TrieInsert(const char *s, int root = 0) {
        if (*s == 0) {
            return ;
        }
        int id = *s - 'a';
        if (nodes[root].c[id] == 0) {
            nodes[cntnodes].reset();
            nodes[root].c[id] = cntnodes++;
            
        }
        TrieInsert(s + 1, nodes[root].c[id]);
    }
    
    bool inTrie(string s) {
        int root = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (nodes[root].c[s[i] - 'a'] == 0) {
                return false;
            }
            root = nodes[root].c[s[i] - 'a'];
        }
        return nodes[root].visted? false: (nodes[root].visted = true);
    }
    
    int cntnodes;
};
