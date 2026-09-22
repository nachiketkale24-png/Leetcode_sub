class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            unordered_map<int,int> mp;
            for(int j=i+1;j<n;j++){
                int target = 0;
                int remaining = target - nums[i] - nums[j];
                if(mp.find(remaining)!=mp.end()){
                    st.insert({nums[i],remaining,nums[j]});
                }
                mp[nums[j]] = 1;
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};