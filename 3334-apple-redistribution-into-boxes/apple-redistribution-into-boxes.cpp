class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=capacity.size();
        int sum=0;
        for(int &i:apple) sum+=i;

        sort(capacity.begin(), capacity.end(), greater<int>());

        for(int i=0; i<n; i++){
            sum-=capacity[i];
            if(sum<=0) return i+1;
        }

        return n;
        
    }
};