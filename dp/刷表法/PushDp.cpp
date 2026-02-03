#include <bits/stdc++.h>
using std::vector;
using std::max;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF=0x3f3f3f3f;
        vector<int>f={0,-INF,-INF};
        for (int x:nums){
            vector<int>g=f;
            for (int i=0;i<3;i++){
                int j=(i+x)%3;
                f[j]=max(f[j],g[i]+x);
            }
        }
        return f[0];
    }
};