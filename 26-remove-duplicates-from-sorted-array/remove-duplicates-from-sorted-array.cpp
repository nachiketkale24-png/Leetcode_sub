class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp; // Number ko key, uski frequency ko value banayenge
        int temp = 0; // Yeh wahi pointer hai jo unique elements ki jagah fix karega
        
        for(int i = 0; i < nums.size(); i++) {
            // Agar number pehli baar mila hai (frequency 0 hai)
            if(mpp[nums[i]] == 0) {
                mpp[nums[i]] = 1;         // Map mein mark kar do ki "dekh liya"
                nums[temp] = nums[i];     // Nayi jagah par usko rakh do
                temp++;                   // Pointer aage badha do
            }
        }
        return temp; 
    }
};