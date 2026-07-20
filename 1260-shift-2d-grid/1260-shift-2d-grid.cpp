class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(m*n);
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i*m+j;
                int nidx=(idx+k)%(m*n);
                int newrow=nidx/m;
                int newcol=nidx%m;
                ans[newrow][newcol]=grid[i][j];
            }
        }
        return ans;
    }
};