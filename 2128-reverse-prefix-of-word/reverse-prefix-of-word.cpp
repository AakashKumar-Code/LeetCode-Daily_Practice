class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();

        int ind=-1;

        for(int i=0; i<n; i++){
            if(word[i]==ch){
                ind=i;
                break;
            }
        }

        if(ind==-1) return word;

        int lo=0, hi=ind;
        while(lo<=hi){
            swap(word[lo++], word[hi--]);
        }

        return word;
        
    }
};