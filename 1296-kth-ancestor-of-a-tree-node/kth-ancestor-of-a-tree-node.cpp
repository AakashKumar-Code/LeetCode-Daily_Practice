class TreeAncestor {
public:

    vector<vector<int>>tab;
    int r, c;

    TreeAncestor(int n, vector<int>& parent) {
        r=n;
        c=log2(n)+1;

        tab=vector<vector<int>>(r, vector<int>(c, -1));

        for(int node=0; node<n; node++){
            tab[node][0]=parent[node];
        }

        for(int j=1; j<c; j++){
            for(int node=0; node<n; node++){
                if(tab[node][j-1]!=-1){
                    tab[node][j]=tab[tab[node][j-1]][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int j=0; j<c; j++){
            if(k&(1<<j)){
                node=tab[node][j];
                if(node==-1) return -1;
            }
        }

        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */