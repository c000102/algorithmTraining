#include <iostream>
using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret =0;

void Add(char c);
void Remove(chare c);

int main(void)
{
    cout << "Sliding Windows 004" << endl;
    int P, S;
    cin >> S >> P;
    int result =0;
    string A;
    cin >> A;
    for(int i=0; i<4; i++){
        cin >> checkArr[i];
        if(checkArr[i] == 0){
            checkSecret++;
        }
    }

    for(int i=0; i<P; i++){
        Add(A[i]);
    }

    if(checkSecret == 4){
        result++;
    }

    for(int i=P; i<S; i++){
        int j=i-P;
        Add(A[i]);
        Remove(A[j]);
        if(checkSecret == 4){
            result++;
        }
    }
    cout << result << endl;
    return 0;
}