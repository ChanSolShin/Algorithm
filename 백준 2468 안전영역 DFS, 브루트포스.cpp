//백준 2468
//DFS, 브루트포스 알고리즘
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[100][100];
int max_length=0;
int area=0;
int max_area=0;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
bool visited[100][100];

void DFS(int a, int b) //인접해있는곳이 물에 잠기지 않았으면 재귀로 방문
{
    visited[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=n||visited[nx][ny]==true)
            continue;
        if(map[nx][ny]>0)
            DFS(nx, ny);
    }
}

void solve()
{
    while(max_length--)// 제일 높은곳이 0이될때까지 반복 (모든곳의 높이가 0이될때까지 반복)
    {
        for(int i=0;i<n; i++)
            {
                for(int j=0; j<n; j++)
                    {
                        if(visited[i][j]!=true&&map[i][j]>0) // 방문하지 않았고, 물에 잠기지 않았으면 DFS로 돌림
                        {
                            DFS(i, j);
                            area++; // 함수를 빠져나오면 구간하나를 측정한것이므로 안전영역의 개수를 +1
                        }
                    }
            }
        
        fill(&visited[0][0], &visited[n - 1][n], false);// 안전영역의 개수를 모두 구했으므로 방문처리배열을 초기화
        if(area>max_area) // 안전영역의 개수 최대치를 구해줌
            max_area=area;
            area=0; // 이제 다시 한칸씩 물에 잠기므로 안전영역 개수를 0으로 초기화
        
        for(int i=0; i<n; i++) // 물에 1씩잠기므로 높이를 1씩 감소
            for(int j=0; j<n; j++)
                map[i][j]--;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; i++) //맵을 입력
    {
        for(int j=0; j<n; j++)
        {
            cin>>map[i][j];
            if(max_length<map[i][j])//맵에서 가장높은곳의 높이를 저장
                max_length=map[i][j];
        }
    }
    solve();
    cout<<max_area;
}
