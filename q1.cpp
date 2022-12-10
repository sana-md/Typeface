#include<bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int vis[1005][1005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> mat[i][j];
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 and mat[i][j]==1){
                int mini1=i,mini2=j;
                int maxi1=i,maxi2=j;
                queue<pair<int,int>>qu;
                qu.push({i,j});
                vis[i][j]=1;
                while(!qu.empty()){
                    auto a=qu.front();
                    int ii=a.first,jj=a.second;
                    qu.pop();
                    vis[ii][jj]=1;
                    mini1=min(mini1,ii);
                    mini2=min(mini2,jj);
                    maxi1=max(maxi1,ii);
                    maxi2=max(maxi2,jj);
                    if(ii>0 and mat[ii-1][jj]==1 and vis[ii-1][jj]==0) qu.push({ii-1,jj});
                    if(jj>0 and mat[ii][jj-1]==1 and vis[ii][jj-1]==0) qu.push({ii,jj-1});
                    if(ii<n-1 and mat[ii+1][jj]==1 and vis[ii+1][jj]==0) qu.push({ii+1,jj});
                    if(jj<m-1 and mat[ii][jj+1]==1 and vis[ii][jj+1]==0) qu.push({ii,jj+1});
                }
                vector<int>temp;
                temp.push_back((mini2+maxi2)/2);
                temp.push_back((mini1+maxi1)/2);
                temp.push_back(maxi2-mini2+1);
                temp.push_back(maxi1-mini1+1);
                ans.push_back(temp);
            }
        }
    }
    for(auto x:ans){
        for(auto y:x) cout << y << ' ';
        cout << '\n';
    }
}
