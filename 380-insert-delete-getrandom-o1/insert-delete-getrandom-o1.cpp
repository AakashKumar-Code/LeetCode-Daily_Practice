class RandomizedSet {
public:


    int cnt;
    int randInd;
    unordered_set<int>st;
    RandomizedSet() {
        cnt=0;
        randInd=0;        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            cnt++;
            return 1;
        }
        return 0;        
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            cnt--;
            return 1;
        }
        return 0;
        
    }
    
    int getRandom() {
        int temp=rand()%cnt;
        int ans=-1;
        for(auto &it:st){
            if(temp==0){
                ans=it;
                break;
            }
            temp--;
        }        
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */