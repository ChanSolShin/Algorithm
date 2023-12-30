#include <iostream>
#include <queue>

using namespace std;

int n,m,u,k;
int map[1000][1000];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int visited[1000][1000]={0,};

void print()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<visited[i][j]<<' ';
        }
        cout<<endl;
    }
}

void BFS(int a,int b)
{
    q.push({a, b});
    
    while(q.size())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) // 상하좌우 갈수있는 땅 탐색
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0 || visited[nx][ny])
                continue; // 갈수 없거나 이미 방문한곳이면 컨티뉴
            
            q.push({nx, ny});
            visited[nx][ny] = visited[a][b] + 1;
        
        }
        
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
            if(map[i][j]==2) // 목표지점 좌표 저장
            {
                u=i;
                k=j;
            }
        }
    }
    BFS(u,k);
    visited[u][k]=0; // 2로 지정한 처음위치를 0으로 처리해줌.
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j]==0&&map[i][j]==1) // 갈수있는 땅이지만 가지못해서 방문배열이 0으로 처리된구역을 -1로 해줌
                visited[i][j]=-1;
        }
    }
    print();
}

int main()
{
    solve();
}
