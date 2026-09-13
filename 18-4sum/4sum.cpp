class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); // O(N log N)
        
        for(int i = 0; i < n; i++) {
            // Avoid duplicates for 'i'
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i + 1; j < n; j++) {
                // Avoid duplicates for 'j'
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while(left < right) {
                    // Use long long to avoid LeetCode's integer overflow trap
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        
                        // Avoid duplicates for 'left' and 'right'
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    } 
                    else if(sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};