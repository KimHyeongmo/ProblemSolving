#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    for(long long i = 1; i <= n; i++)
    {
        long long result = i * i;
        if(result == n)
        {
            return (i+1)*(i+1);
        }
        else if(result > n)
        {
            return -1;
        }
    }
    return -1;
}