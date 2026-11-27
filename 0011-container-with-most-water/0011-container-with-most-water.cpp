class Solution {
public:
    int maxArea(vector<int>& height) {\
        int st=0,end=height.size()-1;
        int maxarea=0;
        while(st<end){
            int ht=min(height[st],height[end]);
            int width=end-st;
            int area=ht*width;
            maxarea=max(maxarea,area);
            if(height[st]<height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxarea;
    }

};