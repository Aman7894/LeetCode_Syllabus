class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a=0;
        int t=0,l=0,b=n-1,r=n-1;
        vector<vector<int>> ans(n,vector<int> (n));
        while(l<=r&&t<=b){
        for(int i=l;i<=r;i++){
            ans[t][i]=++a;
            
        }
        t=t+1;
        for(int j=t;j<=b;j++){
            ans[j][r]=++a;

        }
        r--;
        if(t<=b){
        for(int i=r;i>=l;i--){
            ans[b][i]=++a;
        }
    }
        b--;
        if(l<=r){
        for(int j=b;j>=t;j--){
            ans[j][l]=++a;
        }
    }
        l++;
    }
    return ans;


    }
};