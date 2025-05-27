#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int count[2] = {0,};
    
    for(auto i : s)
    {
        if(i == 'p' || i == 'P')
        {
            count[0]++;
        }
        else if(i == 'y' || i == 'Y')
        {
            count[1]++;
        }
    }
 
    if(count[0] == count[1])
        return true;
    return false;
}