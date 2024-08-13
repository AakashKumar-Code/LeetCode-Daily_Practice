class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k%=n;
        int nk=n-k;
        reverse(arr.begin(), arr.begin()+nk);
        reverse(arr.begin()+nk, arr.end());
        reverse(arr.begin(), arr.end());       
    }
};