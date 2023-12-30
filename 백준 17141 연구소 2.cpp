// x개의 수중애서 n개의 수의 조합을 뽑아서 찾아주는 프로그램
// prev_permutation
// BFS 최소시간

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int find_z=0,w_count=0,large=0,n,m,two_count=0;
bool visited[50][50];
int map[50][50],flag_map[50][50],cnt[50][50]={0,};
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

vector<int>temp;
queue<pair<int, int>>q;
vector<pair<int, int>>v;

bool find_zero() // 맵에서 바이러스가 전파되지않은 곳을 찾는 함수 (찾으면 찾았다는 카운트변수 +1 하고 true 리턴)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==0)
                return true;
        }
    }
    return false;
}

void virus() // 바이러스 전파시키는 함수
{
    while (q.size())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        visited[a][b]=true; // 처음 위치는 방문처리를 해줌으로써 나중에 방문되지 않게 처리
        for(int i=0; i<4; i++)
        {
            int nx=a+dx[i];
            int ny=b+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=n||map[nx][ny]==1||visited[nx][ny]==true)
                continue;
    
            if(map[nx][ny]!=1) // 0이나 2일때 동작 (처음 퍼진 바이러스 위치는 위에서 continue)
            {
                map[nx][ny]=1; // 해당위치를 1로 바꿔서 바이러스 퍼지게 하고
            visited[nx][ny]=true; // 방문처리
            cnt[nx][ny]=cnt[a][b]+1; // cnt 변수에 몇초걸렸는지 세줌
            q.push({nx,ny});
            }
        }
        if(find_zero()==false) // 맵에 0이 없을때 동작
        large=cnt[a][b]; // 가장 마지막에 방문한위치까지 걸린 초를 저장
    }
}

int main()
{
    int min=10000; // 최소시간을 구하는 변수
    cin>>n>>m;
    for(int i=0; i<m; i++) // m개만큼 temp라는 벡터에 1을 푸쉬
    {
        temp.push_back(1);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) // 맵을 입력받고 바이러스를 놓을수있는 칸이면 v라는 벡터에 해당 죄표 푸쉬
        {
            cin>>map[i][j];
            flag_map[i][j]=map[i][j]; // 나중에 맵을 초기화 시켜주기위한 복사본인 flag_map에 map복사
            if(map[i][j]==2)
            {
                v.push_back({i,j});
                two_count++; // 2의 개수를 세는 변수
            }
        }
    }
    for(int i=0; i<two_count-m; i++) // 2의 개수에서 바이러스 위치를 선택할 개수 m을 뺀 값만큼 temp를 0으로 더 채움
        temp.push_back(0);
    
    do {
        w_count++; // while문을 반복한 횟수를 세기위한 w_count를 while 문이 돌때마다 올려주기
           for (int i = 0; i < v.size(); ++i) // 바이러스를 놓을수있는곳중에서 m개를 선택하는 경우의 수를 모두구함
           {
               if (temp[i] == 1)
               {
                   q.push({v[i].first,v[i].second});
                   visited[v[i].first][v[i].second]=true; // 처음 위치는 방문처리
               }
               
           }
        virus();
        if(find_zero()==false) // 0이없을때  최솟값보다 걸린초가 더작으면 대입하고 0이있을때 카운트 +1
        {
            if(large<min)
                min=large;
        }
        else
            find_z++;
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                map[i][j]=flag_map[i][j]; // map을 처음에 입력받았던거로 초기화
            }
        }
        fill(&cnt[0][0], &cnt[0][0] + 50 * 50, 0); // 걸린시간을 세는 변수 0으로 초기화
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false); // 방문처리 변수 초기화
        
       } while (prev_permutation(temp.begin(), temp.end())); // // 전체 2 중에서 m개를 선택하는 경우의 수를 모두구하는 함수
    
    if(find_z==w_count) //만약 모든 경우의수에서 바이러스가 전파되지않을때 -1 출력
    {
        cout<<-1;
        return 0;
    }
    cout<<min; // 걸린시간의 최솟값 출력
}

