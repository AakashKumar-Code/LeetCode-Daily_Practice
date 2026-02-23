class Solution {
public:
    bool hasAllCodes(string s, int k) {
      int n=s.length();

      int i=0, j=0;
      unordered_set<string>st;

      string tmp="";

      for(; j<n; j++){
        tmp+=s[j];
        for(; i<n && tmp.length()>k; i++){
          tmp.erase(0, 1);
        }
        if(j-i+1==k) st.insert(tmp);
      }

      return st.size()==pow(2, k);
        
    }
};