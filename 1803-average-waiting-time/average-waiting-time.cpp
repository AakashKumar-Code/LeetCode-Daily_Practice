class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int currTime=0;
        double sum=0.0;

        for(auto &v:customers){
            int arrivalTime=v[0];
            int cookTime=v[1];

            if(currTime<arrivalTime){
                currTime=arrivalTime;
            }

            int waitTime=currTime+cookTime-arrivalTime;
            sum+=waitTime;
            currTime+=cookTime;
        }

        return sum/n;
    }
};