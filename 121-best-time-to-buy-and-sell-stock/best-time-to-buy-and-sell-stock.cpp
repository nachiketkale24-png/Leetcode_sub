class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = INT_MAX;
        int current = 0;
        int max_pro = 0;
        for(int i=0;i<n;i++){
            current = prices[i];
            min_price = min(min_price,current);
            int profit = current - min_price;
            max_pro = max(max_pro,profit);
        }
        return max_pro;
    }
};