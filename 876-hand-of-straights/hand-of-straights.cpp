class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return 0;
        map<int, int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }

        for(auto it:mpp){
            if(mpp[it.first]>0){
                for(int i=1; i<groupSize; i++){
                    mpp[it.first+i]-=mpp[it.first];
                    if(mpp[it.first+1]<0) return 0;
                }
            }
        }
        return 1;
    }
};