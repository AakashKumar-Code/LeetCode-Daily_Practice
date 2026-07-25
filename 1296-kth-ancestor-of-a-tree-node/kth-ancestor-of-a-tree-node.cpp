class TreeAncestor {
public:

    vector<vector<int>>ancestorTable;
    int row, col;

    TreeAncestor(int n, vector<int>& parent) {
        row=n;
        col=log2(n)+1;

        ancestorTable=vector<vector<int>>(row, vector<int>(col, -1));

        for(int i=0; i<n; i++){
            ancestorTable[i][0]=parent[i];
        }

        for(int j=1; j<col ;j++){
            for(int node=0; node<n; node++){
                if(ancestorTable[node][j-1]>0){
                    ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {

        for(int j=0; j<col; j++){
            if(k&(1<<j)){
                node=ancestorTable[node][j];
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