#include <iostream>
#include <algorithm>
#include<cstdio>
#include<vector>

using namespace std;

vector<int>v;
int map[25][25];
int n;
bool visited[25][25];
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int cnt=0;

void DFS(int a,int b)
{
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=n)
            continue;
        
        if(map[nx][ny]==1&&visited[nx][ny]==false)
        {
            visited[nx][ny]=true;
            cnt++;
            DFS(nx,ny);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==1&&visited[i][j]==false)
            {
                visited[i][j]=true;
                cnt++;
                DFS(i,j);
                v.push_back(cnt);
                cnt=0;
            }
        }
    }
   sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<'\n';
}
