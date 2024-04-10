class Solution {
public:

    bool static comp(string a, string b){
        string temp1=a+b;
        string temp2=b+a;
        return temp1>=temp2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        bool oneZero=0;
        bool nonZero=0;
        for(int &it:nums){
            if(it!=0) nonZero=1;
            temp.push_back(to_string(it));
        }
        if(nonZero==0) return "0";
        sort(temp.begin(), temp.end(), comp);
        string ans="";
        for(auto &it:temp){
            ans+=it;
        }
        return ans;
    }
};