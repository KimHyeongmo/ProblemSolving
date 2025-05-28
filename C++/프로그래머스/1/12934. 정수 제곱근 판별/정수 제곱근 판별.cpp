#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long start = 0;
    switch(n)
    {
        case 1:
            return 4;
        case 4:
            return 9;
        case 9:
            return 16;
        default:
            start = n/4;
    }
        
    for(long long i = 4; i<=start; i++)
    {
        if(i * i == n)
        {
            return (i+1)*(i+1);
        }
    }
    return -1;
}