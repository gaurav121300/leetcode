class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // just add one
                return digits; // no carry needed
            }
            digits[i] = 0;     // digit becomes 0, carry continues
        }
        
        // if we reach here → all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
