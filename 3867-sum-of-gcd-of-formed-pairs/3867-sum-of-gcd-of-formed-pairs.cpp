class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> mx;
        int m=INT_MIN;
        for(int i:nums){
            m=max(m,i);
            mx.push_back(m);
        }
        vector<int> pgcd;
        for(int i=0;i<nums.size();i++){
            pgcd.push_back(gcd(nums[i],mx[i]));
        }
        int s=0,e=pgcd.size()-1;
        long long sum=0;
        sort(pgcd.begin(),pgcd.end());
        while(s<e){
            sum+=gcd(pgcd[s],pgcd[e]);
            s++,e--;
        }
        return sum;
    }
};