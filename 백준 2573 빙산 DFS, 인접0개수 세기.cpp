//백준 2573 빙산
//주변이 0이면 1씩감소하는 문제
//DFS를 돌리면서 주변 0의개수를 세주고 DFS가 다 돌면 각 구역별로 센 0의 개수만큼 빼줌
//0의개수를 세는 map과 똑같은 크기의 2차원배열을 만들어서 같은 구역에 0의 개수를 저장해준다음 for문을 돌려서 나중에 한번에 빼주는것이 포인트
#include <iostream>
#include <algorithm>

using namespace std;

int z_count_map[300][300],map[300][300];
int n,m,area=0,year=0;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool visited[300][300];

bool check_map() // 녹지않고 남아있는 빙산이 있는지 체크하는 함수
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(map[i][j]>0)
                return true;
    }
    return false;
}

void DFS(int a, int b) //상하좌우에 0이 있으면 0을 세는 배열에서 인자로 받은 위치에 0의개수를 저장해줌
{
    visited[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]==true)
            continue;
        if(map[nx][ny]==0) // 이 위치가 0이면
            z_count_map[a][b]++; // 기존위치에는 0이 맞물려있다는것이므로 0을 세주는 배열에서 기존위치부분에 +1해줌
        if(map[nx][ny]>0)
            DFS(nx, ny);
    }
}

void melt() // DFS를 돌고나와서 저장되어있는 주변의 0개수만큼 빙하를 녹여줌.
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            map[i][j]-=z_count_map[i][j];
            if(map[i][j]<0) // 빙하의 높이는 음수가 될 수 없으므로 0으로 바꿔줌
                map[i][j]=0;
        }
    }
    // 빙하를 녹였으므로 0을 세주는 배열과 방문처리 배열및 구역개수를 세는 변수를 초기화시켜주고 한번 녹일때마다 몇년걸렸는지 체크하는 변수를 +1
    fill(&z_count_map[0][0], &z_count_map[n - 1][m],0);
    fill(&visited[0][0], &visited[n - 1][m], false);
    area=0;
    year++;
}

void solve()
{
    while(1)
    {
        for(int i=0;i<n; i++)
            {
                for(int j=0; j<m; j++)
                    {
                        if(visited[i][j]!=true&&map[i][j]>0)
                        {
                            DFS(i, j);
                            area++;//DFS를 돌고나와서 빙하의 개수를 세줌
                        }
                    }
            }
        if(area>=2) // 빙하가 2개 이상으로 분리되어있으면 몇년걸렸는지 출력해주고 프로그램 종료
        {
            cout<<year;
            exit(0);
        }
        melt(); // 인접한 0의 개수만큼 빙하를 녹여주고 초기화
        if(check_map()==false) // 만약 빙하가 모두 녹았으면 다 녹아도 2개 이상으로 분리가 안되므로 0을 출력해주고 프로그램 종료
        {
            cout<<0;
            exit(0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>map[i][j];
    }
    solve();
}
