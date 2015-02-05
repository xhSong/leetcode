class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator < 0 && denominator < 0) {
            return fractionToDecimalU(-numerator, -denominator);
        }
        if (numerator < 0 && denominator > 0) {
            return "-" + fractionToDecimalU(-numerator, denominator);
        }
        if (numerator > 0 && denominator < 0) {
            return "-" + fractionToDecimalU(numerator, -denominator);
        }
        return fractionToDecimalU(numerator, denominator);
    }
    
private:
    string fractionToDecimalU(unsigned numerator, unsigned denominator) {
        unsigned integer = numerator / denominator;
        numerator %= denominator;
        std::string result = std::to_string(integer);
        if (numerator == 0) return result;
        std::vector<unsigned> bits;
        std::map<unsigned, size_t> remainder;
        while (numerator && remainder.find(numerator) == remainder.end()) {
            remainder[numerator] = bits.size();
            bits.push_back(unsigned((unsigned long long)numerator * 10 / denominator));
            numerator = unsigned((unsigned long long)numerator * 10 % denominator);
        }
        result += '.';
        for (size_t i = 0; i < bits.size(); ++i) {
            if (numerator && i == remainder[numerator]) {
                result += '(';
            }
            result += char('0' + bits[i]);
        }
        if (numerator) result += ')';
        return result;
    }
};