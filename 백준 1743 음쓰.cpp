
#include <iostream>

using namespace std;

void trash(int a, int b);
void is_trash(int a, int b);

int trash_size=0;
int max_trash_size=0;
int ground[102][102];
int trash_location_x;
int trash_location_y;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int x,y;

void in_itgrount(int x,int y) // 위치를 모두 0으로 초기화
{
    for(int i=1;i<=y; i++)
    {
        for(int j=1; j<=x; j++)
        {
            ground[i][j]=0;
        }
    }
}

void place_trash(int x, int y)//음식물쓰레기 위치 1로 초기화
{
    ground[x][y]=1;
}


void trash(int a, int b)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (ny > y || nx > x || ny < 0 || nx < 0)
            continue;

        if (ground[nx][ny] == 0) // 음식물쓰레기가 없으면 방문처리
        {
            ground[nx][ny] = -1;
            trash(nx, ny);
        }
       else if (ground[nx][ny] == 1) // 음식물쓰레기가 있으면 방문처리 후 다음위치 탐색
        {
            ground[nx][ny] = 2;
            is_trash(nx, ny);
            if(trash_size>max_trash_size)
                max_trash_size=trash_size;
            trash_size=0;
        }
    }
   
}
void is_trash(int a,int b) //음식물 쓰레기를 발견했을때 다음위치 탐색함수
{
    trash_size++;
    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (ny > x || nx > y || ny < 0 || nx < 0)
            continue;

        if (ground[nx][ny] == 0)
        {
            ground[nx][ny] = -1; // 현 위치 방문처리
        }
       else if (ground[nx][ny] == 1)
        {
            ground[nx][ny] = 2; // 현위치 음식물쓰레기 방문처리
            is_trash(nx, ny);
        }
    }
    
}
void check()
{
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            trash(i, j);
        }
    }
}

int main()
{
        int k;
        cin>>x>>y>>k;
        in_itgrount(x, y);
        for(int j=0; j<k; j++) //음식물 쓰레기 위치입력
        {
            cin>>trash_location_x>>trash_location_y;
            place_trash(trash_location_x, trash_location_y);
        }
        check();
        cout<<max_trash_size;
    }


