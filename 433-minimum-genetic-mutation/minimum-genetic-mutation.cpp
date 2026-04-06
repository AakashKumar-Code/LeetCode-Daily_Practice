class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>b={bank.begin(), bank.end()};
        if(b.find(endGene)==b.end()) return -1;
        if (startGene == endGene) return 0;
        int steps=0;
        unordered_set<string>vis;
        vector<char>change{'A','G', 'T', 'C'};

        queue<string>q;
        vis.insert(startGene);
        q.push(startGene);

        while(!q.empty()){
          int sz=q.size();
          for(int i=0; i<sz; i++){
            string node=q.front();
            q.pop();

            if(node==endGene) return steps;

            for(int x=0; x<node.length(); x++){
              char org=node[x];
              for(int t=0; t<4; t++){
                char ch=change[t];
                if(org==ch) continue;
                string tmp=node;
                tmp[x]=ch;
                if(b.find(tmp)!=b.end() && vis.find(tmp)==vis.end()){
                  vis.insert(tmp);
                  q.push(tmp);                  
                }
              }
            }
          }
          steps++;
        }

        return -1;
    }
};