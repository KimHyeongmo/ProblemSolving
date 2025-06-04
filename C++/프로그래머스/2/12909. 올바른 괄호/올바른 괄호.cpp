#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{    
    int correct = 0;
    
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == '(')
            correct++;
        else if(s[i] == ')')
            correct--;
        
        if(correct < 0)
            return false;
    }
    if(correct > 0)
        return false;
    
    return true;
}