class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(), people.end());

        int cnt=0;
        int i=0, j=n-1;

        while(i<j){
            if(people[i]+people[j]<=limit){
                cnt++;
                people[i]=0;
                people[j]=0;
                i++;
                j--;
            }else{
                j--;
            }
        }
        for(int i=0; i<n; i++){
            if(people[i]>0) cnt++;
        }

        return cnt;

        
    }
};