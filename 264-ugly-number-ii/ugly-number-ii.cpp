class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n+1];
        int i2, i3, i5;
        i2=i3=i5=1;
        arr[1]=1;
        for(int i=2; i<=n; i++){
            int a2=arr[i2]*2;
            int a3=arr[i3]*3;
            int a5=arr[i5]*5;
            int mini=min({a2, a3, a5});
            arr[i]=mini;
            if(a2==mini){
                i2++;
            }
            if(a3==mini){
                i3++;
            }
            if(a5==mini){
                i5++;
            }
        }
        return arr[n];
    }
};