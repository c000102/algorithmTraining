/*
문제:
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다.
이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면,
그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.

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

#include <iostream>
using namespace std;

#define MAX (100)
int M, N, K; //세로크기, 가로크기, 직사각형 개수
int sx[MAX + 10];
int sy[MAX + 10];
int ex[MAX + 10];
int ey[MAX + 10];

int sol[MAX * MAX]; //각 영역 넓이 저장용

int paper[MAX+10][MAX+10];

#if 0
void InputData()
{
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
}
#else
void InputData(){
    M=5, N=7, K=3;
    sx[0] = 0, sy[0] = 2, ex[0] = 4, ey[0] = 4;
    sx[1] = 1, sy[1] = 1, ex[1] = 2, ey[1] = 3;
    sx[2] = 4, sy[2] = 0, ex[2] = 6, ey[2] = 2;
}
#endif
void OutputData(int ans)
{
    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

void fillPaper(int sx, int sy, int ex, int ey){
    for(int y=sy; y<M; y++){
        for(int x=sx; x<N; x++){
            paper[x][y] = 1;
        }
    }
}

int solve(void){
    int cnt=0;

    for(int i=0; i<K; i++)
        fillPaper(sx[i], sy[i], ex[i], ey[i]);

    

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); //입력받는 부분

    //여기서부터 작성
    ans = solve();

    OutputData(ans); //출력하는 부분
    return 0;
}