class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1; // Start index at the end
        
        // 1. Tera while loop: Right se left aakar dip (breakpoint) dhundna
        while (n > 0) {
            if (nums[n] <= nums[n - 1]) {
                n--;
            } else {
                break;
            }
        }
        n--; // Ab 'n' tere dip element ka index ban gaya hai

        // 2. Tera 'b' aur 'temp' wala difference logic
        if (n >= 0) {
            int b = nums[n]; // Tera breakpoint
            int temp = 10000000; 
            int swap_idx = -1;

            // Pura right-side scan karke b se JUST bada number (minimum diff) dhundna
            for (int i = n + 1; i < nums.size(); i++) {
                if (nums[i] > b && nums[i] <= temp) {
                    temp = nums[i];
                    swap_idx = i;
                }
            }
            swap(nums[n], nums[swap_idx]);
        }

        // 3. Tera incomplete two-pointer reverse logic
        int left = n + 1;  
        int right = nums.size() - 1; 

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;  
            right--; 
        }
    }
};