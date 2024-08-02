class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int ans=0;
        int n=bank.size();
        vector<bool>vis(n, 0);
        int m=startGene.length();

        if(n==0) return -1;

        queue<string>q;

        q.push(startGene);

        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int t=0; t<sz; t++){
                string node=q.front();
                q.pop();
                
                if(node==endGene) return ans-1;

                for(int i=0; i<n; i++){
                    if(vis[i]) continue;
                    int diff=0;
                    for(int j=0; j<m; j++){
                        if(node[j]!=bank[i][j]) diff++;
                    }
                    if(diff==1){
                        vis[i]=1;
                        q.push(bank[i]);
                    }
                }                
            }
        }
        return -1;
        
    }
};