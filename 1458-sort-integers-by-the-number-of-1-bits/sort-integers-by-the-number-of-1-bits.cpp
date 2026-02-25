class Solution {
public:

    bool static comp(int &a, int &b){
        int x=__builtin_popcount(a);
        int y=__builtin_popcount(b);
        if(x<y) return 1;
        else if(x==y) return a<b;
        else return 0;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;        
    }
};