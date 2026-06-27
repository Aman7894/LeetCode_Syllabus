class Solution {
public:
    int helper(int row,int col){
        int ans=1;
        for(int i=0;i<col;i++){
            ans=ans*(row-i);
            ans=ans/(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
       for(int i=1;i<=numRows;i++){
        vector<int> temp;
        for(int j=0;j<i;j++){
           int p=helper(i-1,j);
           temp.push_back(p);
        }
        ans.push_back(temp);
       }
       
        return ans;
    }
};