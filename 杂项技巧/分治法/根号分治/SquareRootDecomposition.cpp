//根号分治
//x<=sqrt(n)时,预处理
//x>sqrt(n),暴力枚举

//洛谷(https://www.luogu.com.cn/problem/P3396)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1,0);
    for (int i=1;i<=n;i++) cin>>a[i];
    int s= int(sqrt(n));
    //dp数组,f[i][j]表示模i==j的下标对应的数的累加和
    vector<vector<int>> f(s + 1, vector<int>(s + 1, 0));
    //预处理dp数组
    for (int i=1;i<=s;i++){
        for (int j=1;j<=n;j++)
            f[i][j%i]+=a[j];
    }

    char op;
    int x,y,t=m;
    while(t--){
        cin>>op>>x>>y;
        if (op=='A'){
            if (x<=s) cout<<f[x][y]<<endl;
            else{
                int ans=0;
                for (int i=y;i<=n;i+=x) ans+=a[i];
                cout<<ans<<endl;
            }
        }
        else{
            int v=y-a[x];
            a[x]=y;
            for (int i=1;i<=s;i++) f[i][x%i]+=v;
        }
    }
    return 0;
}

//写法2
//#include <bits/stdc++.h>
//using namespace std;
//
//class Solver {
//public:
//    int n, m, s;
//    vector<int> a;
//    vector<vector<int>> f;
//
//    void build() {
//        s = (int)sqrt(n);
//        f.assign(s + 1, vector<int>(s + 1, 0));
//        for (int mod = 1; mod <= s; mod++) {
//            for (int i = 1; i <= n; i++) {
//                f[mod][i % mod] += a[i];
//            }
//        }
//    }
//
//    int query(int x, int y) {
//        if (x <= s) return f[x][y % x];
//        int ans = 0;
//        for (int i = y; i <= n; i += x) ans += a[i];
//        return ans;
//    }
//
//    void update(int x, int y) {
//        int d = y - a[x];
//        a[x] = y;
//        for (int mod = 1; mod <= s; mod++) {
//            f[mod][x % mod] += d;
//        }
//    }
//
//    void solve() {
//        cin >> n >> m;
//        a.assign(n + 1, 0);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//
//        build();
//
//        while (m--) {
//            char op;
//            int x, y;
//            cin >> op >> x >> y;
//            if (op == 'A') {
//                cout << query(x, y) << '\n';
//            } else {
//                update(x, y);
//            }
//        }
//    }
//};
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    Solver solver;
//    solver.solve();
//    return 0;
//}

//写法3
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//
//    int s = (int)sqrt(n);
//    vector<vector<int>> f(s + 1, vector<int>(s + 1, 0));
//
//    auto build = [&]() {
//        for (int mod = 1; mod <= s; mod++) {
//            for (int i = 1; i <= n; i++) {
//                f[mod][i % mod] += a[i];
//            }
//        }
//    };
//
//    auto query = [&](int x, int y) -> int {
//        if (x <= s) return f[x][y % x];
//        int ans = 0;
//        for (int i = y; i <= n; i += x) ans += a[i];
//        return ans;
//    };
//
//    auto update = [&](int x, int y) {
//        int d = y - a[x];
//        a[x] = y;
//        for (int mod = 1; mod <= s; mod++) {
//            f[mod][x % mod] += d;
//        }
//    };
//
//    build();
//
//    while (m--) {
//        char op;
//        int x, y;
//        cin >> op >> x >> y;
//        if (op == 'A') cout << query(x, y) << '\n';
//        else update(x, y);
//    }
//
//    return 0;
//}
