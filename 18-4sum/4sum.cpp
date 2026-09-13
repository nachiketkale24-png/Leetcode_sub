class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st; 
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                unordered_set<long long> hashset; // Remaining dhundhne ke liye
                
                for(int k = j + 1; k < n; k++) {
                    long long sum3 = (long long)nums[i] + nums[j] + nums[k];
                    long long remaining = target - sum3;
                    
                    if(hashset.find(remaining) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)remaining};
                        sort(temp.begin(), temp.end()); 
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};