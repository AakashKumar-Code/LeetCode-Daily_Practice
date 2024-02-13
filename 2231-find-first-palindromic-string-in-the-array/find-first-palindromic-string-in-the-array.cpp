class Solution {
public:

    bool isPal(string a){
        int i=0, j=a.length()-1;
        while(i<=j){
            if(a[i]!=a[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0; i<n; i++){
            if(isPal(words[i])) return words[i];
        }
        return "";
    }
};