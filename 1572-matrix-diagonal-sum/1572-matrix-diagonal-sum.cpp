class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s1=0;
        int s2=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            s1+=mat[i][i];
        }
        for(int i=0;i<n;i++){
            if(i!=(n-1-i)){
                s2+=mat[i][n-i-1];
            }
        }
        int res=s1+s2;

        return res;

    }
};