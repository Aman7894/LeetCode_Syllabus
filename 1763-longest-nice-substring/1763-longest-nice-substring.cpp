class Solution {
public:
    bool isNice(string sub){
    unordered_set<char> st(sub.begin(), sub.end());

    for(char c : sub){
        if(islower(c)){
            if(st.find(toupper(c)) == st.end())
                return false;
        }
        else{
            if(st.find(tolower(c)) == st.end())
                return false;
        }
    }

    return true;
}
    string longestNiceSubstring(string s) {
        int n=s.length();
        string ans="";
       for(int i = 0; i < n; i++){
         for(int j = i; j < n; j++){
          string sub = s.substr(i, j - i + 1);
           if(isNice(sub)){   
            if (sub.length() > ans.length()) {
                ans = sub;
            }
           }
        }
       }

       return ans;
    }

    
};