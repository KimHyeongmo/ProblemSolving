#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int count[10] = {0,};
    while(0 != n)
    {
        count[n%10]++;
        n/=10;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; j < count[i]; j++)
        {
            answer += i;
            answer *= 10;
        }
    }
    
    return answer/10;
}