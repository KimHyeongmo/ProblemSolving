#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if(a==b)
        return a;
    
    int big = 0;
    int small = 0;
    
    if(a > b)
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }
    
    int total = big - small + 1;
    answer = total * (long long)(a + b) / 2;
    
    return answer;
    
}