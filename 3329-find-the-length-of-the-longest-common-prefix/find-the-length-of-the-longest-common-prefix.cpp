class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();

        unordered_set<string>st;

        for(int i=0; i<n; i++){
            int num=arr1[i];
            while(num){
                st.insert(to_string(num));
                num/=10;
            }
        }

        int maxi=0;

        for(int i=0; i<m; i++){
            int num=arr2[i];
            while(num){
                string str=to_string(num);
                if(st.find(str)!=st.end()){
                    int len=str.length();
                    maxi=max(maxi, len);
                    break;
                }
                num/=10;
            }
        }

        return maxi;
    }
};