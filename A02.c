/*
문제:
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다.
이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면,
그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.

<그림 1>///////////
 O X O O O O O
 X X X X O O O
 X X X X O O O
 O X O O X X O
 O O O O X X O
///////////////////

첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다.
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다.
모눈종이의 왼쪽 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
in:
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2

ou:
3
1 7 13
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX (100)
int M, N, K; //세로크기, 가로크기, 직사각형 개수
int sx[MAX + 10];
int sy[MAX + 10];
int ex[MAX + 10];
int ey[MAX + 10];

int sol[MAX * MAX]; //각 영역 넓이 저장용

int imap[MAX+10][MAX+10];
int area=0;

#if 0
void InputData()
{
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &sx[i], &sy[i], &ex[i], &ey[i]);
    }
}
#else
void InputData()
{
    M = 5, N = 7, K = 3;
    sx[0] = 0, sy[0] = 2, ex[0] = 4, ey[0] = 4;
    sx[1] = 1, sy[1] = 1, ex[1] = 2, ey[1] = 5;
    sx[2] = 4, sy[2] = 0, ex[2] = 6, ey[2] = 2;
}
#endif

void OutputData(int ans)
{
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void printMap(void)
{
    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            int val = imap[y][x];
            printf(" %d", val);      
        }
        printf("\n");
    }
}

void floodFill(int y, int x){
    if(y<0 || y >=M || x<0 || x>=N) return;
    if(imap[y][x] != 0) return;

    imap[y][x]=2;
    area++;
    
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];

        floodFill(ny, nx);
    }
}

int solve(){
    int cnt =0;

    for(int i=0; i<K; i++){
        for(int iy=sy[i]; iy<ey[i]; iy++){
            for(int ix=sx[i]; ix<ex[i]; ix++){
                imap[iy][ix] = 1;
            }
        }
    }

    for(int iy=0; iy<M; iy++){
        for(int ix=0; ix<N; ix++){
            if(imap[iy][ix]!=0) continue;

            area=0;
            floodFill(iy, ix);
            sol[cnt++] = area;
        }
    }

    printMap();

    return cnt;
}

int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int ans = -1;
    InputData(); //입력받는 부분

    //여기서부터 작성
    ans = solve();

    qsort(sol, ans, sizeof(sol[0]), comp);

    printf("\n\n");
    OutputData(ans); //출력하는 부분
    return 0;
}