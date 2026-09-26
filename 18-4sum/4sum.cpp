class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st; // Unique quadruplets filter karne ke liye
        
        for(int i = 0; i < n; i++) {
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        
                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end()); // Set mein duplicate arrays rokne ke liye sorting zaroori hai
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};