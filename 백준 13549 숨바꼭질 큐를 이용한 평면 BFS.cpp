ㅈ#include <iostream>
#include <algorithm> // fill 함수를 사용하기 위한 헤더 파일
#include <queue>
#define MAX 100000 + 1 // 최대 크기 매크로로 설정

using namespace std;

int n,k;
int Visit[MAX]; // int형 배열로 몇초걸렸는지 추가해주기

int bfs(int x)
{
    queue<int> Q;
        Q.push(n);
        Visit[n] = 0;
     
        while (Q.empty() == 0)
        {
            int Pos = Q.front(); // 현재 위치
            Q.pop();
     
            if (Pos == k)
                return Visit[k]; //k번째에 몇초걸렸는지를 리턴
            
            if (Pos + 1 < MAX && Visit[Pos + 1] > Visit[Pos] + 1) // 최대값 보다 작거나 방문하지 않았어야함
            {
                Visit[Pos + 1] = Visit[Pos] + 1; // 다음위치에 이동시간 1초추가해서 넣기
                Q.push(Pos + 1);
            }
     
            if (Pos - 1 >= 0 && Visit[Pos - 1] > Visit[Pos] + 1) // 0보다 크거나 방문하지 않았어야함
            {
                Visit[Pos - 1] = Visit[Pos] + 1; // 다음위치에 이동시간 1초추가해서 넣기
                Q.push(Pos - 1);
            }
     
            if (Pos * 2 < MAX && Visit[Pos * 2] > Visit[Pos]) // 최대값 보다 작거나 방문하지 않았어야함
            {
                Visit[Pos * 2] = Visit[Pos]; // 순간이동 이므로 *2한곳에 이동시간 그대로 넘어가기
                Q.push(Pos * 2);
            }
        }
    return 0;
}


int main()
{
    cin>>n>>k;
    fill(Visit, Visit+MAX, 999999999);
    int result=bfs(n);
    cout<<result;
    
}

// n=5, k=17, 이면 Q에는 5 /4 6 10/ 3 5 8/ 5 7 12/ 9 11 20/ 4 2 6/ 4 6 10/ 7 9 16/
//                          5       4      6        10      3       5       8

// 이렇게 큐에 다 한번씩들어가서 17이 될때까지 돌려서 찾기

