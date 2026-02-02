#include <bits/stdc++.h>
using namespace std;
//Floyd算法用于求全源最短路,时间复杂度O(n^3),可以求任意两点间最短距离,可以求解负权图
//start,end,weight分别代表边的起点,终点及边权,n代表点的数量,返回值为nxn数组,d[i][j]表示i~j之间最短路
vector<vector<int>> Floyd(vector<int>start,vector<int>end,vector<int>weight,int n){
    const int INF = 0x3f3f3f3f;
    vector<vector<int>>d(n,vector<int>(n,INF));
    for (int i=0;i<n;i++) d[i][i]=0;
    for (int i=0;i<start.size();i++){
        int x=start[i];
        int y=end[i];
        int z=weight[i];
        d[x][y]=min(z,d[x][y]);
    }
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++){
            if (d[i][k]==INF) continue;
            for (int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    return d;
}

//实例:https://leetcode.cn/problems/minimum-cost-to-convert-string-i/description/