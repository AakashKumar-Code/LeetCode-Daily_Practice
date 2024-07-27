class Solution {
public:

    int find(int x, vector<int>&par){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x], par);
    }

    void Union(int x, int y, vector<int>&par, vector<int>&rank){
        int par_x=find(x, par);
        int par_y=find(y, par);
        if(par_x==par_y) return;

        if(rank[par_x]>rank[par_y]){
            par[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            par[par_x]=par_y;
        }else{
            par[par_x]=par_y;
            rank[par_y]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int>par1(26), rank1(26, 0);        

        for(int i=0; i<26; i++){
            par1[i]=i;
        }

        int n=equations.size();

        for(int i=0; i<n; i++){
            string s=equations[i];           

            if(s[1]=='='){                
                Union(s[0]-'a', s[3]-'a', par1, rank1);
            }
        }

        for(int i=0; i<n; i++){
            string s=equations[i];

            if(s[1]=='!'){
                int u=find(s[0]-'a', par1);
                int v=find(s[3]-'a', par1);
                if(u==v) return 0;
            }
        }        

        return 1;
    }
};