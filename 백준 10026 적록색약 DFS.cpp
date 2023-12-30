//일반인일때 보이는그림과 적록색약이 보이는 그림을 따로 나누어서 풀이함.
//원래 그림을 입력받아서 초록색을 빨간색으로 바꿔주어서 다른 그림배열에 저장.
//따로따로 DFS를 돌려서 각각 구역마다 각각의 카운트 변수를 더해줌
//visited 배열을 만들어서 방문한곳을 다시 돌지 않도록해줌

#include <iostream>

using namespace std;

char map[100][100];
char non_map[100][100];
int n;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool visited[100][100];
bool non_visited[100][100];
int s_count=0;
int non_count=0;

void DFS(int a,int b) //일반인이 보이는 그림
{
    visited[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n||visited[nx][ny]!=false)
            continue;
        if(map[a][b]==map[nx][ny])
        {
            DFS(nx, ny);
        }
    }
}

void non_DFS(int a,int b)//적록색약이 보이는 그림
{
    non_visited[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n||non_visited[nx][ny]!=false)
            continue;
        if(non_map[a][b]==non_map[nx][ny])
        {
            non_DFS(nx, ny);
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
            cin>>map[i][j];
            non_map[i][j]=map[i][j];
            if(map[i][j]=='G') // 초록색일때 적록색약이 보이는 그림에서 초록색을 모두 빨간색으로 통일시켜줌
            {
                non_map[i][j]='R';
            }
        }
    }
    
    for(int i=0;i<n; i++) // 각각 따로따로 DFS를 전체적으로 돌려줌
    {
        for(int j=0; j<n; j++)
        {
            if(visited[i][j]!=true)
            {
                DFS(i, j);
                s_count++;
            }
            if(non_visited[i][j]!=true)
            {
                non_DFS(i, j);
                non_count++;
            }
        }
    }
    cout<<s_count<<' '<<non_count;
    
}
