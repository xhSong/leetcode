class RotationStr {
public:
    char str[10];
    int id, len;
    RotationStr() {}
    RotationStr(string s, int id) {
        len = s.size();
        this->id = id;
        for (int i = 0; i < len; ++i) {
            str[i] = s[i];
        }
    }
    void rotate() {
        char temp = str[0];
        for (int i = 1; i < len; ++i) {
            str[i - 1] = str[i];
        }
        str[len - 1] = temp;
    }
    
    bool operator < (const RotationStr &other) const {
        return strncmp(str, other.str, len - 1) < 0;
    }
    
    bool operator == (const RotationStr &other) const {
        return strncmp(str, other.str, len - 1) == 0;
    }
};

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        allstr.clear();
        res.clear();
        
        if (dict.size() == 0) return res;
        if (start == end) {
            vector<string> justone(1, start);
            res.push_back(justone);
            return  res;
        }
        
        allstr.push_back(make_pair(start, 1));
        allstr.push_back(make_pair(end, 0));
        
        for (unordered_set<string>::iterator pos = dict.begin(); pos != dict.end(); ++ pos) {
            if (*pos != start && *pos != end) {
                allstr.push_back(make_pair(*pos, 0));
            }
        }
        
        _makeLinks();
        
        int step = _ladderLen();
        
        stk.clear();
        stk.push_back(1);
        _DFS(step);
        return res;
    }
    
private:
    int _ladderLen() {
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int now_id = que.front();
            que.pop();
            int now_step = allstr[now_id].second;
            if (now_id == 1) return now_step;
            for (int i = 0; i < links[now_id].size(); ++i) {
                if (allstr[links[now_id][i]].second == 0) {
                    allstr[links[now_id][i]].second = now_step + 1;
                    que.push(links[now_id][i]);
                }
            }
        }
        return 0;
    }
    
    void _makeLinks() {
        vector<RotationStr> dicts;
        links.clear();
        links.resize(allstr.size());
        int len = allstr[0].first.size();
        for (int i = 0; i < allstr.size(); ++i) {
            dicts.push_back(RotationStr(allstr[i].first, i));
        }
        for (int k = 0; k < len; ++k) {
            for (int i = 0; i < dicts.size(); ++i) {
                dicts[i].rotate();
            }
            sort(dicts.begin(), dicts.end());
            for (int i = 0; i < dicts.size(); ++i) {
                for (int j = i + 1; j < dicts.size() && dicts[i] == dicts[j]; ++j) {
                    links[dicts[i].id].push_back(dicts[j].id);
                    links[dicts[j].id].push_back(dicts[i].id);
                }
            }
        }
    }
    
    void _DFS(int step) {
        int now = stk[stk.size() - 1];
        if (allstr[now].second != step + 1 - stk.size()) return ;
        if (stk.size() == step) {
            if (now == 0) {
                vector<string> oneres;
                for (int i = stk.size() - 1; i >= 0; --i) {
                    oneres.push_back(allstr[stk[i]].first);
                }
                res.push_back(oneres);
            }
            return ;
        }
        for (int i = 0; i < links[now].size(); ++i) {
            stk.push_back(links[now][i]);
            _DFS(step);
            stk.pop_back();
        }
    }
    
    vector<int> stk;
    vector<vector<string> > res;
    vector<pair<string, int> > allstr;
    vector<vector<int> > links;
};