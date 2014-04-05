class Solution {
public:
    string simplifyPath(string path) {
        vector<string> files = split(path);
        vector<string> newfiles;
        for (int i = 0; i < files.size(); ++i) {
            if (files[i] == "..") {
                if (newfiles.size()) newfiles.pop_back();
            } else if (files[i] == "" || files[i] == ".") {
                
            } else {
                newfiles.push_back(files[i]);
            }
        }
        if (newfiles.size() == 0) return "/";
        string newpath;
        for (int i = 0; i < newfiles.size(); ++i) {
            newpath.push_back('/');
            for (int j = 0; j < newfiles[i].size(); ++j) {
                newpath.push_back(newfiles[i][j]);
            }
        }
        return newpath;
    }
private:
    vector<string> split(string path, char c = '/') {
        vector<string> ans;
        string dir;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == c) {
                ans.push_back(dir);
                dir = "";
            } else {
                dir.push_back(path[i]);
            }
        }
        ans.push_back(dir);
        return ans;
    }
};