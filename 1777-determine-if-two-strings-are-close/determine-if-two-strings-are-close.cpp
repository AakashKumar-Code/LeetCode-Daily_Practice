class Solution {
public:
    
    int n;
    bool check(string &s, string &t){
        unordered_set<char>st;
        for(int i=0; i<n; i++){
            st.insert(s[i]);
        }
        for(int i=0; i<n; i++){
            if(st.find(t[i])==st.end()) return 0;
        }
        return 1;
    }

    bool closeStrings(string word1, string word2) {
        map<char, int>mp1, mp2;
        n=word1.length();
        if(n!=word2.length()) return 0;

        for(int i=0; i<n; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        vector<int>temp1, temp2;
        for(auto &it:mp1){
            temp1.push_back(it.second);
        }
        for(auto &it:mp2){
            temp2.push_back(it.second);
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        return temp1==temp2 && check(word1, word2);
    }
};