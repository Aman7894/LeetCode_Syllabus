class Solution {
public:
    int helper(int i, int j){
        long long  ans=1;
        for(int k=0;k<j;k++){
            ans=ans*(i-k);
            ans=ans/(k+1);
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        int row=rowIndex+1;
        vector<vector<int>> ans;
        for(int i=1;i<=row;i++){
            vector<int> temp;
            for(int j=0;j<i;j++){
                temp.push_back(helper(i-1,j));
            }
            ans.push_back({temp});
        }
        return ans[row-1];
    }
};