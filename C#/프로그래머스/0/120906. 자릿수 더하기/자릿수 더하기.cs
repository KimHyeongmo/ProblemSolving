using System;

public class Solution {
    public int solution(int n) {
        int answer = 0;
    int r;
    while(n > 0)
    {
        r = n%10;
        answer += r;
        n = n/10;
    }
    
    return answer;
        return answer;
    }
}