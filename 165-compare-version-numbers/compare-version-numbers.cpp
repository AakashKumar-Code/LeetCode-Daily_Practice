class Solution {
public:

    vector<string> getVec(string s){
        stringstream ss(s);
        vector<string>ans;
        string token="";
        while(getline(ss, token, '.')){
            ans.push_back(token);
        }
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<string>a=getVec(version1);
        vector<string>b=getVec(version2);

        int i=0, n=a.size(), m=b.size();

        while(i<max(n, m)){
            int x=i<n?stoi(a[i]):0;
            int y=i<m?stoi(b[i]):0;
            if(x<y) return -1;
            else if(x>y) return 1;
            i++;
        }
        return 0;
    }
};