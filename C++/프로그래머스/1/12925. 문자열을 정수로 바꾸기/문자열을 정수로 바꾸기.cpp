#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool minus = false;
    for(auto i : s)
    {
        if(i == '-')
        {
            minus = true;
            continue;
        }
        else if(i == '+')
            continue;
        
        answer += (i-'0');
        answer *= 10;
    }
    if(minus)
        answer *= -1;
    
    return answer/10;
}