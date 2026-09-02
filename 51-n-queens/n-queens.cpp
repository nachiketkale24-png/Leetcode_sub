class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> X(n+1,0);
        NQueens(0,n,X,ans);
        return ans;
    }
    void NQueens(int k, int n, vector<int>& X, vector<vector<string>>& ans){
        for(int i=0;i<n;i++){
            if(Place(k,i,X)){
                X[k]=i;
                if(k==n-1){
                    vector<string> board;
                    for(int row=0;row<n;row++){
                        string s(n,'.');
                        s[X[row]] = 'Q';
                        board.push_back(s);
                    }
                    ans.push_back(board);
                }
                else{
                    NQueens(k+1,n,X,ans);
                }
            }
        }
    }
    bool Place(int k, int i, vector<int>& X){
        for(int j=0;j<=k-1;j++){
            if(X[j]==i){
                return false;
            }
            else if(abs(X[j]-i)==abs(j-k)){
                return false;
            }
        }
        return true;
    }

};