class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int>comb={1, 2, 3, 4, 5, 6, 7, 8, 9};
        int temp1=low, temp2=high;
        int sz1=0, sz2=0;
        while(temp1){
            sz1++;
            temp1/=10;
        }
        while(temp2){
            sz2++;
            temp2/=10;
        }
        vector<int>ans;        
        for(int k=sz1; k<=sz2; k++){
            for(int i=0; i<9-k+1; i++){
                int num=0;
                for(int j=i; j<i+k; j++){
                    num=(num*10)+comb[j];
                }
                if(num>=low && num<=high){
                    ans.push_back(num);
                }

            }
        }
        return ans; 
    }
};