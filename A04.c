/*
문제:
학생들이 건강하지 못하다고 생각한 선생님은 학생들을 위한 마라톤 대회를 열었고, 우승 후보인 기연이도 이 대회에 참가할 예정이다.
마라톤 코스는 N(3≤N≤100,000)개의 체크 포인트로 구성되어 있으며,
1번 체크포인트에서 시작해서 모든 체크 포인트를 순서대로 방문한 후 N번 체크포인트에서 마라톤이 끝난다.
기연이는 우승해야 한다는 부담감 때문에 중간에 있는 체크포인트 한 개를 몰래 건너 뛰려고 한다. 단, 1번과 N번 체크포인트는 건너 뛰지 않을 생각이다.

기연이가 체크포인트 한 개를 건너뛰면서 달릴 수 있다면, 과연 달려야 하는 최소 거리는 얼마일까?

참고로, 마라톤 대회는 수원시내 한복판에서 진행될 예정이기 때문에 거리는 “맨하탄 거리”로 측정한다.
위치(X1, Y1)와 위치(X2, Y2)의 거리는 |X1-X2| + |Y1-Y2|이다. (|X|는 절대값 기호이다)

첫 번째 줄에는 체크포인트 수 N이 입력된다
두 번째 줄부터 N줄에 걸쳐 각 체크포인트의 X, Y좌표가 공백으로 구분되어 입력된다
(-1,000≤X≤1,000), (-1,000≤Y≤1,000)
체크포인트는 방문해야 하는 순서대로 입력된다.
동일한 위치에 여러 체크포인트가 있을 수 있다.
기연이는 이러한 체크포인트가 있을 때도 한 체크포인트만 건너 뛰지 동일 위치의 모든 체크포인트를 건너 뛰지 않는다.
in:
4
0 0
8 3
11 -1
10 0

기연이가 체크포인트 1개를 건너뛰고 달릴 수 있는 최소 거리를 출력한다
ou:
14

*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];

#if 0
void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
    }
}
#else
void InputData(void)
{
    N = 4;
    X[1] = 0, Y[1] = 0;
    X[2] = 8, Y[2] = 3;
    X[3] = 11, Y[3] = -1;
    X[4] = 10, Y[4] = 0;
}
#endif

int dist(int a, int b){
    return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}

int solve(void){
    int minDist = (int)(4e8);

    for(int s=2; s<N; s++){
        int sum =0;
        for(int i=1; i<N; i++){
            if(i==s) continue;
            if(i+1 == s) sum+=dist(i, i+2);
            else sum += dist(i, i+1);
        }
        if(minDist > sum) minDist = sum;
    }
    
    return minDist;
}

int main(void)
{
    int ans = -1;

    InputData(); //입력받는 부분

    //여기서부터 작성
    ans = solve();

    printf("%d\n", ans); //출력하는 부분
    return 0;
}