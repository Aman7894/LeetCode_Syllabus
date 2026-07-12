class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==1) return {1};
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     for(int i=0;i<arr.size();i++){
        pq.push({arr[i],i});
     }
     int n=arr.size();
     vector<int> ans(n);
     int rank=1;
     int prev=NULL;
     while(pq.size()){
        auto[val,idx]=pq.top();
        pq.pop();
        if(val!=prev){
            prev=val;
            ans[idx]=rank;
            rank++;
        }
        else{
            ans[idx]=rank-1;
        }
     }
     return ans;
    }
};