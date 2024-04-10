class RandomizedSet {
public:

    unordered_set<int>st;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            return 1;
        }else return 0;        
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            return 1;
        }else return 0;
        
    }
    
    int getRandom() {
        int n=st.size();
        int num=(rand()%n);
        int cnt=0;
        for(int x:st){
            if(cnt==num) return x;
            cnt++;            
        }
        return rand()%n;        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */