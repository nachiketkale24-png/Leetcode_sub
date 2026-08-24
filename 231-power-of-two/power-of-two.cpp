class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n must be positive, and n & (n - 1) must kill the only set bit to become 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};
