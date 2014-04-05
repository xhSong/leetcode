class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> triplet(3);
        sort(num.begin(), num.end());
        int i = 0;
        do {
            int j = i + 1, k = num.size() - 1;
            do {
                while(j < k && num[i] + num[j] + num[k] > 0) {
                    -- k;
                } 
                if (j < k && num[i] + num[j] + num[k] == 0) {
                    triplet[0] = num[i], 
                    triplet[1] = num[j], 
                    triplet[2] = num[k], 
                    ans.push_back(triplet);
                }
                ++ j;
                while(j < k && num[j] == num[j - 1]) ++j;
            } while (j < k);
            ++ i;
            while (i < num.size() && num[i] == num[i - 1]) ++i;
        } while (i < num.size());
        
        return ans;
    }
};