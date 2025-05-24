#include <string>
#include <vector>

using namespace std;

bool DivideMoc(int number, int division, int& start)
{
    if((number / division) >= division)
    {
        start = division;
        return true;
    }
    return false;
}

void CalType(int number, int& start)
{
    if(DivideMoc(number, 1000, start))
        return;
    if(DivideMoc(number, 500, start))
        return;
    if(DivideMoc(number, 250, start))
        return;
    if(DivideMoc(number, 100, start))
        return;
    if(DivideMoc(number, 50, start))
        return;
    if(DivideMoc(number, 10, start))
        return;

    start = 1;
    return;
}

int solution(int n) {
    
    int start = 1;
    CalType(n, start);
    for(int i = start; i <= 1000000; i++)
    {
        if(n / i == i && n % i == 0)
        {
            return 1;
        }
    }
    
    return 2;
    
}