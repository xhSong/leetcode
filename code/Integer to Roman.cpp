class Solution {
public:
    string intToRoman(int num) {
        char r1 = 'I', r5 = 'V', r10 = 'X', r50 = 'L', r100 = 'C', r500 = 'D', r1000 = 'M';
        string roman;
        roman += digital2roman(num / 1000, r1000, ' ', ' ');
        roman += digital2roman(num % 1000 / 100, r100, r500, r1000);
        roman += digital2roman(num % 100 / 10, r10, r50, r100);
        roman += digital2roman(num % 10, r1, r5, r10);
        return roman;
    }
    
private:
    string digital2roman(int x, char c1, char c5, char c10) {
        string roman;
        if (1 <= x && x <= 3) {
            switch (x) {
                case 3:
                    roman.push_back(c1);
                case 2:
                    roman.push_back(c1);
                case 1:
                    roman.push_back(c1);
            }
        } else if (x == 4) {
            roman.push_back(c1);
            roman.push_back(c5);
        } else if (5 <= x && x <= 8) {
            roman.push_back(c5);
            switch (x) {
                case 8:
                    roman.push_back(c1);
                case 7:
                    roman.push_back(c1);
                case 6 :
                    roman.push_back(c1);
            }
        } else if (x == 9) {
            roman.push_back(c1);
            roman.push_back(c10);
        }
        return roman;
    }
};