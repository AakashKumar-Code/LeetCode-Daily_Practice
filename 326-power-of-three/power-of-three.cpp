class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_set<int>st={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
        if(st.find(n)!=st.end()) return true;
        else return false;
        
    }
};

