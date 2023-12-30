// 백준 2146 다리만들기
// DFS로 섬을 각각 구분한후 BFS로 각섬끼리의 최단거리를 찾아주는 문제

#include <iostream>
#include <queue>

using namespace std;

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

int map[100][100];
int n,island_num=2,length=0,min_length=999999,map_num=999999;
int visited[100][100]={0,};
queue<pair<int, int>> q;

void BFS(int a,int b) // 섬끼리의 최단거리를 찾아내는 탐색함수
{
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0); // 방문처리 배열을 초기화
    visited[a][b] = 1;
    q.push({a, b});
    
    while(q.size())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == map_num || visited[nx][ny])
                continue; // 맵을 벗어나거나 같은 섬의 구역일때 컨티뉴
            
            q.push({nx, ny});
            visited[nx][ny] = visited[a][b] + 1;
        
            if(map[nx][ny]>1) // 다른섬에 도착했을때
            {
                length=visited[nx][ny]-2; // 출발지와 도착지를 모두 카운트 해주었으므로 -2를 빼서 다리의 길이를 변수에 저장
                if(min_length>length) // length가 더 작으면 min_length에 length 저장후 리턴
                    min_length=length;
                return;
            }
        }
        
    }
}

void DFS(int a,int b) // 각 섬을 구분하는 함수 (번호를 붙여서 구분함)
{
    map[a][b]=island_num; // island_num이라는 변수를 이용하여 각섬에 1이 아닌 다른 번호를 지정해줌. 그리고 다른 섬을 탐색할때 island_num을 +1 해주어서 각각 다른번호로 구분.
    for(int i=0; i<4; i++)
    {
            int nx=a+dx[i];
            int ny=b+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=n||map[nx][ny]==0) // 섬이 아닐때 컨티뉴
                continue;
            if(map[nx][ny]==1) // 만약 섬일때 재귀로 돔
                DFS(nx,ny);
    }
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>map[i][j];
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==1)// 1일때만 탐색하므로 이미 탐색해서 1보다 크게 지정된부분은 탐색하지 않음
            {
                DFS(i,j);
                island_num++; // 한 섬을 탐색한후 번호를 붙인다음 다음 섬을 찾을때 island_num을 +1해줌
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]!=0) // 섬일때 탐색
            {
                map_num=map[i][j]; // 그 구역의 섬인지 확인하기 위한 변수
                BFS(i,j);
                q = queue<pair<int, int>>(); // 큐를 초기화
            }
        }
    }
   cout<<min_length;
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
}


