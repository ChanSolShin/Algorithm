// 백준 3184 양
// 울타리들 안의 양과 늑대의 개수 세주는 프로그램

#include <iostream>

using namespace std;

char map[250][250];
int o_count=0;
int v_count=0;
bool visited[250][250];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m;
int total_v_count=0;
int total_o_count=0;

void DFS(int a,int b)
{
    visited[a][b]=true; // DFS 들어와서 늑대와 양이 있으면 개수를 카운트해줌
    if(map[a][b]=='v')
        v_count++;
    if(map[a][b]=='o')
        o_count++;
    
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]==true||map[nx][ny]=='#') // 울타리가 아닐때 방문해서 탐색해줌
            continue;
            DFS(nx,ny);
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(map[i][j]!='#'&&visited[i][j]!=true) //울타리가 아니거나 방문을 하지 않았을때 탐색
                DFS(i,j);
            if(v_count<o_count) // 늑대보다 양이 많으면 늑대의 개수 0처리
                v_count=0;
            else
                o_count=0; // 그외의 경우 양의 개수를 0으로 처리
            total_v_count+=v_count; // 각각 처리해준후 총 양과 늑대의 개수를 각각 더해줌
            total_o_count+=o_count;
            v_count=0;
            o_count=0;
        }
    }
    cout<<total_o_count<<' '<<total_v_count;
}


int main()
{
    ios::sync_with_stdio(0);
    solve();
}
