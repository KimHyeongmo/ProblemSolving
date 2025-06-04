#include <string>
#include <vector>

using namespace std;

bool yaksoo(int number)
{
    int yaks = 0;
    for(int i = 1; i<=number; i++)
    {
        if(number%i == 0)
        {
            yaks += 2;
            if(i == number/i)
            {
                yaks--;
                break;
            }
        }
        if(i > number/i)
        {
            break;
        }
    }
    if(yaks % 2 == 0)
        return true;    
    else
        return false;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i<=right; i++)
    {
        if(yaksoo(i))
        {
            answer+=i;
        }
        else
        {
            answer-=i;
        }
    }
    
    return answer;
}