//백준 2468 치즈
//정석대로라면 큐를사용해서 BFS를 돌려서 풀어야하지만 큐를 사용하지 않고 DFS를 이용해서 풀이를함.
//내부공기는 치즈가 녹는데 영향을 주지 않으므로 0,0부터 DFS를 돌려서 외부공기에 닿는 치즈를 찾아냄
//외부공기부터 DFS를 돌리므로 내부공기는 치즈에 영향을 주지 않음.

#include <iostream>
#include <algorithm>

using namespace std;

int map[100][100];
int n,m;
bool visited[100][100];
int melting[100][100];
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int time_count=0;

bool check_map() // 남은 치즈가 있는지 확인하는 함수
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(map[i][j]>0)
                return true;
    }
    return false;
}

void DFS(int a, int b) // 외부공기(0)을 만나면 재귀로 돌고 치즈(1)를 만나면 외부공기를 만났다는 변수에 +1을 해줌.
{
    visited[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]==true)
            continue;
        if(map[nx][ny]==1) //외부공기가 치즈를 만났으므로 그 치즈는 외부공기에 닿은 횟수 +1
            melting[nx][ny]++;
        if(map[nx][ny]==0) // 외부공기가 외부공기를 만났으므로 그 외부공기에 들어가서 상하좌우 탐색
            DFS(nx, ny);
    }
}

void melt()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            
        {
            if(melting[i][j]>1) // 치즈가 2면이상 외부공기와 맞닿아있을때 치즈를 녹여줌
                map[i][j]=0;
        }
    }
    // 치즈를 한시간동안 녹였으니까 다시 녹여야하므로 모두 초기화시켜주고 시간을 세는 변수 +1을 해줌
    fill(&melting[0][0], &melting[n - 1][m],0);
    fill(&visited[0][0], &visited[n - 1][m], false);
    time_count++;
}

void solve()
{
    while(1)
    {
        DFS(0,0); // 무조건 외부공기일수밖에없는 (0,0) 부터 DFS를 실행
        if(check_map()==false) // 치즈가 다 녹았으면 소요된 시간을 출력하고 프로그램 종료
        {
            cout<<time_count;
            exit(0);
        }
        melt(); // DFS를 돌고 나왔으므로 치즈를 녹이는 함수를 실행시킴
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>map[i][j];
    }
    solve();
}
