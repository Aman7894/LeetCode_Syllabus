class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
       for(int i=0;i<patterns.size();i++){
        string s=patterns[i];
       if (word.find(s)!=string::npos) c++;
       }
       return c;
    }
};