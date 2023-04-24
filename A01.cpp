/*
문제:
가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.
이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.
이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 둘레의 길이를 구하는 프로그램을 작성하시오.

첫째 줄에 색종이의 수가 주어진다.
이어 둘째 줄부터 한 줄에 하나씩 색종이를 붙인 위치가 주어진다.
색종이를 붙인 위치는 두 개의 자연수로 주어지는데 첫 번째 자연수는 색종이의 왼쪽 변과 도화지의 왼쪽 변 사이의 거리이고,
두 번째 자연수는 색종이의 아래쪽 변과 도화지의 아래쪽 변 사이의 거리이다.
색종이의 수는 100이하이며, 색종이가 도화지 밖으로 나가는 경우는 없다.
in:
4
3 7
5 2
15 7
13 14

ou:
96
*/

#include <iostream>
using namespace std;

#define maxn (100+10)

int N;
int A[maxn];
int B[maxn];

int paper[maxn][maxn];

#if 0
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
}
#else
void InputData()
{
    N = 4;
    A[0] = 3, B[0] = 7;
    A[1] = 5, B[1] = 2;
    A[2] = 15, B[2] = 7;
    A[3] = 13, B[3] = 14;
}
#endif

void fillPaper(int r, int c){
    for(int i=r; i<r+10; i++){
        for(int j=c; j<c+10; j++){
            paper[i][j] = 1;
        }
    }
}

int check(int y, int x){
    int cnt =0;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny<0 || ny>99 || nx<0 || nx>99 || paper[ny][nx]==0 ) cnt++;

    }

    return cnt;
}

int solve(void){
    int sum =0;

    for(int i=0; i<N; i++)
        fillPaper(A[i],B[i]);

    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++){
            if(paper[i][j] == 0) continue;
            sum += check(i, j);
        }

    return sum;
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}