class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        vector<vector<int>> visited_matrix(m,vector<int>(n,0));
        if (matrix.empty()) return ans;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};

        int a = 0;  //direction
        int b = 0;   //initial valuess of starting point
        int c = 0;

        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[b][c]);
            visited_matrix[b][c] = 1;
            int next_dr = b + dr[a];
            int next_dc = c + dc[a];
            if(next_dr>=0 && next_dr<m && next_dc>=0 && next_dc<n && visited_matrix[next_dr][next_dc]!=1){
                b = next_dr;
                c = next_dc;
            }
            else{
                a = (a+1)%4;   //rotating 90 degree
                b = b + dr[a];
                c = c + dc[a];
            }
        }
        return ans;
    }
};