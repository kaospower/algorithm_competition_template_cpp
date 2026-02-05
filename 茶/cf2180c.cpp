//
// Created by knmfr on 2/5/2026.
//

//猜想,构造
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k, n);
    if (k % 2 == 0) {
        int free = 0;
        //__ln(n)=n的二进制位数-1
        for (int i = __lg(n); i >= 0; i--) {
            if ((n >> i) & 1) {
                a[min(free, k - 1)] ^= 1 << i;
                free++;
            } else {
                //free&~1,将free的最低位置0
                for (int j = 0; j < min(free & ~1, k); j++) a[j] |= 1 << i;
            }
        }
    }
    for (int x: a) cout << x << " ";
}

int main() {
    //关闭输入流同步,速度更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}