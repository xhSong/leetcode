class Solution {
public:
    int compareVersion(string version1, string version2) {
        int sub = vecsub(version2vec(version1), version2vec(version2));
        return min(1, max(-1, sub));
    }
private:
    vector<int> version2vec(const string& v) {
        vector<int> vec;
        size_t dot1 = -1, dot2;
        while ((dot2 = v.find('.', dot1 + 1)) != string::npos) {
            vec.push_back(atoi(v.substr(dot1 + 1, dot2 - dot1 - 1).c_str()));
            dot1 = dot2;
        }
        vec.push_back(atoi(v.substr(dot1 + 1).c_str()));
        return vec;
    }
    
    int vecsub(const vector<int>& v1, const vector<int>& v2) {
        for (size_t i = 0; i < v1.size() || i < v2.size(); ++i) {
            if (!(i < v1.size())) {
                if (v2[i] != 0) return -1;
            } else if (!(i < v2.size())) {
                if (v1[i] != 0) return 1;
            } else if (v1[i] != v2[i]) return v1[i] - v2[i];
        }
        return 0;
    }
};