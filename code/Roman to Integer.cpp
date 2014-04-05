class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        const char r1 = 'I', r5 = 'V', r10 = 'X', r50 = 'L', r100 = 'C', r500 = 'D', r1000 = 'M';
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case r1000:
                    ans += 1000;
                    break;
                case r500:
                    ans += 500;
                    break;
                case r100:
                    if (i + 1 < s.size() && (s[i + 1] == r1000 || s[i + 1] == r500)) {
                        ans -= 100;
                    } else {
                        ans += 100;
                    }
                    break;
                case r50:
                    ans += 50;
                    break;
                case r10:
                    if (i + 1 < s.size() && (s[i + 1] == r100 || s[i + 1] == r50)) {
                        ans -= 10;
                    } else {
                        ans += 10;
                    }
                    break;
                case r5:
                    ans += 5;
                    break;
                case r1:
                    if (i + 1 < s.size() && (s[i + 1] == r10 || s[i + 1] == r5)) {
                        ans -= 1;
                    } else {
                        ans += 1;
                    }
            }
        }
        return ans;
    }
};