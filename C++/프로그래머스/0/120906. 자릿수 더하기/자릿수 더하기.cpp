#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int k;
    while(n > 0)
    {
        k = n%10;
        answer += k;
        n = n/10;
    }
    
    return answer;
}