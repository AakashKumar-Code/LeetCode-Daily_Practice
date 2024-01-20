class Solution {
public:
int sumSubarrayMins(vector<int>& arr) {
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1;
        } else {
            left[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first > arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n;
        } else {
            right[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long temp = (i - left[i]) * (right[i] - i) % mod;
        temp=(temp*arr[i]) % mod;
        temp = (temp + mod) % mod; 
        sum = (sum + temp) % mod;
    }
    
    return sum;
}


};