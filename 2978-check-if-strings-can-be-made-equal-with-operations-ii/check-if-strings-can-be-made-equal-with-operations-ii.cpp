class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        int even[26]={0}, odd[26]={0};

        for(int i=0; i<n; i++){
            if((i%2)==0){
                even[s1[i]-'a']++;
            }else odd[s1[i]-'a']++;
        }

        for(int i=0; i<n; i++){
            if(s1[i]==s2[i]){
                if((i%2)==0){
                    even[s1[i]-'a']--;
                }else odd[s1[i]-'a']--;
            }else if((i%2)==0 && even[s2[i]-'a']>0){
                even[s2[i]-'a']--;
            }else if((i%2)==1 && odd[s2[i]-'a']>0){
                odd[s2[i]-'a']--;                
            }else return false;
        }

        for(int i=0; i<26; i++){
            if(even[i]<0 || odd[i]<0) return  false;
        }

        return true;        
    }
};