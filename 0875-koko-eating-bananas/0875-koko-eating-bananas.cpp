class Solution {
public:
    bool fn(vector<int>& piles ,int mid,int h){
        int a_h = 0;
        for(int i:piles){
            a_h+=i/mid;
            if(i%mid!=0){
                a_h++;
            }
        }
        return a_h<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int m=l+(r-l)/2;
            if(fn(piles,m,h)){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};