//두번 째 곱해지는 값을 소모하는 덧셈 횟수라 생각해보면,
//높은 값에 대하여 그 소모 횟수를 더 적게, 낮은 값에 대하여 그 소모 횟수를 최대한 많이 빼놓아야 한다고 생각하면,
//두 값을 정렬, 역정렬하여, 앞부터 쌍을 만들어 곱해주면 최솟값이 나올 수 있다.
//최대값은 동일 정렬.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for(int i = 0; i<A.size(); i++)
    {
        answer += (A[i] * B[i]);
    }

    return answer;
}