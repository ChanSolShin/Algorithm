#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int visited[51][51], _max, ret, n, m;
string s;
char a[54][54]; // 맵
queue<pair<int, int>> q;


void bfs(int y, int x)
{
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0); //방문처리 배열을 모두 0으로 초기화
    visited[y][x] = 1; // 현재위치 1로 방문처리 및 이동한거리 +해주기
    q.push({y, x}); //큐에 현재 좌표 넣기
    _max = 0;
    
    while(q.size()) //큐가 비어있지 않을때 반복
    {
        int y = q.front().first; // 큐의 앞에서 노드 추출
        int x = q.front().second;
        q.pop(); // 가장 앞에 있는 큐 제거
        for(int i = 0; i < 4; i++) //만약 상하좌우에 육지가없으면 while문 종료
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'W' || visited[ny][nx])
                continue;       //맵의 범위를 벗어났거나 육지가 아니거나,이미 방문한 구역은 컨티뉴
            
            visited[ny][nx] = visited[y][x] + 1; // 이동하면서 +1 해주기.
            q.push({ny, nx}); // 큐에 현재위치 삽입
            
            if(_max <= visited[ny][nx]) // 맥스보다 현재이동한 위치가 더 크면 맥스에 대입
            {
                _max = visited[ny][nx];
            }
        }
    }
}
int main()
{
    cin >> n >> m; //크기 입력
    for(int i = 0; i < n; i++) //문자열로 입력받아서 맵에 대입 (하나씩 입력받아도됨)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 'L') //육지가 나오면 BFS 돌리기
            {
                bfs(i, j);
              ret = max(ret, _max); // _max랑 ret 비교해서 더 큰값을 ret으로 대입. if(ret<_max) ret=_max 와같음.
            }
        }
    }
    cout << ret - 1; // 이동한거리이므로 처음위치 1은 마이너스 해주어야함.
}
