class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        int n=arr.size();
        stack<int>st1, st2;
        st1.push(arr[0]);
        st2.push(arr[1]);

        for(int i=2; i<n; i++){
            if(st1.top()>st2.top()){
                st1.push(arr[i]);
            }else st2.push(arr[i]);
        }

        vector<int>ans;

        while(!st1.empty()){
            ans.push_back(st1.top());
            st1.pop();
        }

        reverse(ans.begin(), ans.end());
        vector<int>ans2;

        while(!st2.empty()){
            ans2.push_back(st2.top());
            st2.pop();
        }

        reverse(ans2.begin(), ans2.end());

        ans.insert(ans.end(), ans2.begin(), ans2.end());

        return ans;
    }
};