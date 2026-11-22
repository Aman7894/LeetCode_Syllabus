class Solution {
public:
    bool checkString(string s) {
        bool istrue= false;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(istrue){
                    return false;
                }
                else{
                    continue;
                }
            } 
            else{
                istrue = true;
            }
        }
        return true;
    }
};