class Solution {
public:

    int solve(int ind, unordered_set<char>&st, vector<string>&arr){
        if(ind<0) return 0;
        int take=0;
        if(st.empty()){
            for(int i=0; i<arr[ind].length(); i++){
                if(st.find(arr[ind][i])==st.end()){
                    st.insert(arr[ind][i]);
                }else{
                    st.clear();
                    break;
                }
            }
            if(!st.empty()){
                take=arr[ind].length()+solve(ind-1, st, arr);
                st.clear();
            }
        }else{
            unordered_set<char>st1, st2;
            for(int i=0; i<arr[ind].length(); i++){
                if((st.find(arr[ind][i])!=st.end()) || 
                   (st1.find(arr[ind][i])!=st1.end())){
                       st1.clear();
                       break;
                   }else{
                       st1.insert(arr[ind][i]);
                   }
            }
            if(!st1.empty()){
                st2.insert(st.begin(), st.end());
                st2.insert(st1.begin(), st1.end());
                take=arr[ind].length()+solve(ind-1, st2, arr);
                //st.erase(st1.begin(), st1.end());
            }
        }
        int ntake=solve(ind-1, st, arr);
        return max(take, ntake);
    }

    int maxLength(vector<string>& arr) {
        int n=arr.size();
        unordered_set<char>st;
        return solve(n-1, st, arr);
    }
};