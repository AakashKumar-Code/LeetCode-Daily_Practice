class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string, int>mpp;
        for(auto &it:patterns){
            mpp[it]++;
        }
        int cnt=0;
        int n=word.length();
        for(int i=0; i<n; i++){
            string str="";
            for(int j=i; j<n; j++){
                str+=word[j];
                if(mpp.find(str)!=mpp.end()){
                    cnt+=mpp[str];
                    mpp.erase(str);
                }
            }
        }
        return cnt;
    }
};