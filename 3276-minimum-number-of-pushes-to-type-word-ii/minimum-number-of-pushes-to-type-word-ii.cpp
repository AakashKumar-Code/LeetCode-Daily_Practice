class Solution {
public:
    int minimumPushes(string word) {
        int mp[26]={0};
        int n=word.size();

        for(int i=0; i<n; i++){
            mp[word[i]-'a']++;
        }

         vector<int> v(mp, mp + 26);
        sort(v.begin(), v.end(), greater<int>());

        int ans = 0;
        int freq = 1;
        int cnt = 0;

        // Calculate the minimum pushes required
        for (int i = 0; i < 26; i++) {
            if (v[i] == 0) break;  // No more characters left to process

            ans += (v[i] * freq);
            cnt++;

            if (cnt == 8) {
                freq++;
                cnt = 0;
            }
        }

        return ans;

        
    }
};