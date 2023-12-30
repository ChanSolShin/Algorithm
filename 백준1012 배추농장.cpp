#include <iostream>
#include <stack>

using namespace std;
void plant(int a, int b);
void is_cabbages(int a, int b);
int earthworm_count=0;//지렁이 개수
int ground[50][50];
int cabbage_location_x;
int cabbage_location_y;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int x,y; // 농장 크기

void in_itgrount(int x,int y) // 배추 농장 크기 초기화
{
    for(int i=0;i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            ground[i][j]=0;
        }
    }
}

void Planting_cabbages(int x, int y) // 배추 위치 저장
{
    ground[y][x]=1;
}


void plant(int a, int b)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (ny >= x || nx >= y || ny < 0 || nx < 0) // 농장의 크기를 벗어나면 컨티뉴
            continue;

        if (ground[nx][ny] == 0) // 만약 배추가 없으면 방문처리하고 다음 확인할 위치로 넘어가기
        {
            ground[nx][ny] = -1;
            plant(nx, ny);
        }
       else if (ground[nx][ny] == 1) // 만약 배추가 있으면 다음 위치로가서 배추위치 확인
        {
            ground[nx][ny] = 2;// 배추위치 방문처리
            is_cabbages(nx, ny);
            earthworm_count++;
        }
    }
}
void is_cabbages(int a,int b) //배추가 있을때 검사
{
    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (ny >= x || nx >= y || ny < 0 || nx < 0) // 농장의 크기를 벗어나면 컨티뉴
            continue;

        if (ground[nx][ny] == 0) // 만약 배추가 없으면 방문처리
        {
            ground[nx][ny] = -1;
        }
       else if (ground[nx][ny] == 1) // 만약 배추가 있으면 다음 위치로가서 배추위치 확인
        {
            ground[nx][ny] = 2;// 배추위치 방문처리
            is_cabbages(nx, ny);
        }
    }
}
void check()
{
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            plant(i, j);
        }
    }
}

int main()
{
    int t,k;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        earthworm_count=0;
        cin>>x>>y>>k;
        in_itgrount(x, y);
        for(int j=0; j<k; j++)
        {
            cin>>cabbage_location_x>>cabbage_location_y;
            Planting_cabbages(cabbage_location_x, cabbage_location_y);
        }
        //    for(int i=0;i<y; i++) //체크전 농장 확인
        //    {
        //        for(int j=0; j<x; j++)
        //        {
        //            cout<<ground[i][j]<<' ';
        //        }
        //        cout<<endl;
        //    }
        //    cout<<endl;
        check();
        //    for(int i=0;i<y; i++) //체크후 농장확인
        //    {
        //        for(int j=0; j<x; j++)
        //        {
        //            cout<<ground[i][j]<<' ';
        //        }
        //        cout<<endl;
        //    }
        //    cout<<endl;
        cout<<earthworm_count<<endl;
    }
}
