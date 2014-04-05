class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (next_permutation(num.begin(), num.end()) == false) {
            sort(num.begin(), num.end());
        }
    }
};