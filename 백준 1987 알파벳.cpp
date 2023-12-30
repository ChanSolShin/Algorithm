//백준 1987 알파벳 DFS
//(0,0)부터 가장 멀리갈수있는 지점을 찾아야함
//지금까지 지나온 알파벳으로는 못지나감
//알파벳의 개수가 크기인 배열을 선언해서 알파벳을 방문할때마다 그 알파벳의 해당하는 순서에 배열의 값을 +1 해주어서 그 알파벳을 지나감을 표시해줌
//예를 들어 A는 배열의 0번째이며, B는 배열의 1번째이고 방문할때마다 그 배열의 값을 +1 해주어서 방문처리 해주었음

#include <iostream>

using namespace std;

int n,m,ans=0,max_ans=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char map[20][20];
int alpa[26];

void DFS(int a, int b)
{
    alpa[map[a][b]-64]++; // 그 알파벳을 방문한 횟수를 카운트
    ans++; // 지나온 경로를 +1 해줌
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        
        if(nx<0||ny<0||nx>=n||ny>=m||alpa[map[nx][ny]-64]) // 이 알파벳이 방문한적있는지 체크해서 방문을 했으면 continue 처리
            continue;
        DFS(nx,ny);
        alpa[map[nx][ny]-64]--; // DFS에서 나와서 다른경로를 찾아야하므로 이 알파벳의 방문횟수를 감소시켜줌
    }
    if(max_ans<ans) // 최대 경로를 저장해줌
        max_ans=ans;
    ans--; // DFS를 돌고나오므로 경로횟수를 감소시켜줌
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>map[i][j];
    }
    DFS(0,0);
    cout<<max_ans;
}
