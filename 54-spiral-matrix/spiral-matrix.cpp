class Solution {
public:
    // Function ka naam 'ans' se badal kar 'solve' kar diya
    void solve(vector<vector<int>>& matrix, int r, int c, int dir, vector<int>& res, vector<vector<int>>& visited) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Current cell ko result mein daalo aur visited mark karo
        res.push_back(matrix[r][c]);
        visited[r][c] = 1;
        
        // 4 Directions: Right(0), Down(1), Left(2), Up(3)
        // dr aur dc hume batate hain ki x aur y axis pe kahan jana hai
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        // Pehle current direction mein aage badhne ki koshish karo
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        // Agar aage ka rasta safe hai aur visited nahi hai, toh aage badho
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited[nr][nc] == 0) {
            solve(matrix, nr, nc, dir, res, visited);
        } else {
            // Agar deewar aagayi ya visited array mil gaya, toh 90 degree turn lo
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
            
            // Turn lene ke baad check karo ki valid rasta bacha hai ya end aagaya
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited[nr][nc] == 0) {
                solve(matrix, nr, nc, dir, res, visited);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // columns
        
        // visited array ko size ke BAAD define kiya
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        // Start from row 0, col 0, facing Right (direction 0)
        solve(matrix, 0, 0, 0, res, visited);
        
        return res;
    }
};