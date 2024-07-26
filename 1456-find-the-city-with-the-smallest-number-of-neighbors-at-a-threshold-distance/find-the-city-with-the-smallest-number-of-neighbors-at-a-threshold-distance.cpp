class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>arr(n, vector<int>(n, 1e9));

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            arr[u][v]=wt;
            arr[v][u]=wt;
        }

        for(int i=0; i<n; i++){
            arr[i][i]=0;
        }

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    
                    arr[i][j]=min(arr[i][j], arr[i][via]+arr[via][j]);
                }
            }
        }

        int ans=-1, mini=1e9;

        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(i!=j && arr[i][j]<=distanceThreshold) cnt++;
            }
            if(mini>=cnt){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};