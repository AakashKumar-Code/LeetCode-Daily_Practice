class Solution {
public:
    int n;
    
    int check1(string s, char ch){
      int cnt=0, maxi=0;
      for(int i=0; i<n; i++){
        if(s[i]==ch){
          cnt++;
          maxi=max(maxi, cnt);
        }else cnt=0;
      }
      return maxi;
    }

    int check2(string s, char ch1, char ch2){
      int cnt=0, maxi=0;

      unordered_map<int, int>pre;
      pre[0]=-1;

      for(int i=0; i<n; i++){
        if(s[i]==ch1) cnt++;
        else if(s[i]==ch2){
          cnt--;
        }else{
            pre=unordered_map<int, int>();
            pre[0]=i;
            cnt=0;
        }
        if(pre.count(cnt)>0){
          maxi=max(maxi, i-pre[cnt]);
        }else pre[cnt]=i;
      }

      return maxi;
    }

    int longestBalanced(string s) {
      n=s.length();
      int maxi=0;
      maxi=max(maxi, check1(s, 'a'));
      maxi=max(maxi, check1(s, 'b'));
      maxi=max(maxi, check1(s, 'c'));

      maxi=max(maxi, check2(s, 'a', 'b'));
      maxi=max(maxi, check2(s, 'b', 'c'));
      maxi=max(maxi, check2(s, 'a', 'c'));

      int cnt1=0, cnt2=0;

      map<pair<int, int>, int>mpp;
      mpp[{0, 0}]=-1;

      for(int i=0; i<n; i++){
        if(s[i]=='a'){
          cnt1--;
          cnt2--;
        }else if(s[i]=='b'){
          cnt1++;
        }else cnt2++;
        if(mpp.count({cnt1, cnt2})){
          maxi=max(maxi, i-mpp[{cnt1, cnt2}]);
        }else mpp[{cnt1, cnt2}]=i;
      }

      return maxi;        
    }
};