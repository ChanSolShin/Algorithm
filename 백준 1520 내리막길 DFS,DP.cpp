//일반적인 DFS 방식으로 풀면 범위가 크기 때문에 시간초과가 난다.
//따라서 DP를 이용해서 시간복잡도를 줄여야한다.
// dp 배열을 이용해서 목적지 까지 갈수있는 경로의 개수만 알려주었다.
// dp가 0일 경우 목적지에 도달할수 있는 경우의 수가 없다는 뜻이다.
// 다음 위치를 계속 탐색하면서 목적지까지 도달 할 수 있는 수를 더 해준다.
// 목적지에 도달하면 1을 리턴해서 갈수있는 위치를 방문하면서 계속 더해준다.


#include <iostream>

using namespace std;

int n,m;
int map[500][500];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
int dp[500][500];

int DFS(int a,int b)
{
    if(a==n-1&&b==m-1) // 목적지에 도달하면 1을 리턴해서 갈수있는 경로의 카운트를 늘려준다.
        return 1;
    if (dp[a][b] != -1)
        return dp[a][b];

    dp[a][b]=0;
        for(int i=0; i<4; i++)
        {
            int nx=a+dx[i];
            int ny=b+dy[i];
            if(nx>=n||ny>=m||nx<0||ny<0)
                continue;
            if(map[a][b]>map[nx][ny])
                dp[a][b] = dp[a][b] + DFS(nx, ny);
        }
    return dp[a][b];
}


int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>map[i][j];
            dp[i][j] = -1;
        }
    }
    cout<< DFS(0,0);
}
