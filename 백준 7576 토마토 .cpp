/*
    * 1) 입력받은 토마토 정보에서 익은 것들을 모두 큐에 집어 넣고,
    * 2) 큐가 비어있지 않으면, 1일을 추가하고 현재 큐에 존재하는 원소들의 수 만큼 반복문을 돌며 큐에서 토마토 정보를 꺼낸다.
    * 3) 현재 토마토에서 인접한 익지않은 토마토에 대한 정보를 큐에 삽입
    * 4) 큐가 비어있다면, 토마토 배열을 검사해서 익지않은 토마토가 존재하는지 확인
    * 5) 만약 익지않은 토마토가 존재한다면 토마토가 익기 위해 필요한 최소 일 수는 -1로 지정
    * 6) 그렇지 않으면 토마토가 익기 위해 필요한 최소 일 수를 리턴한다.
    */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>>q;
int n,m;
int map[1000][1000];
bool visited[1000][1000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cnt[1000][1000]={0,};

void tomato()
{
    while (q.size())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=a+dx[i];
            int ny=b+dy[i];
            
            if(nx<0||ny<0||nx>=m||ny>=n||map[nx][ny]==-1||visited[nx][ny]==true)
                continue;
            if(map[nx][ny]!=1)
            {
                map[nx][ny]=1;
            visited[nx][ny]=true;
            cnt[nx][ny]=cnt[a][b]+1;
            q.push({nx,ny});
            }
            
        }
    }
}


int main()
{
    cin>>n>>m;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>map[i][j];
            if(map[i][j]==1)
                q.push({i,j});
        }
    }
    
    tomato();
    int max=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==0)
            {
                cout<<-1;
                return 0;
            }
            if(max<cnt[i][j])
            {
                max=cnt[i][j];
            }
        }
    }

    cout<<max;
    
}

