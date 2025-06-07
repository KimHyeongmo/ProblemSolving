#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> table = vector<bool>(n+1);
    
    for (int i = 1; i<=n; i++)
    {
        table[i] = false;
    }
    
    for(int i = 2; i<=n; i++)
    {
        if(table[i])
            continue;
        for(int j = 2; j <= n/i; j++)
        {
            int tempt = i*j;
            if(tempt > 100)
            {
                break;
            }
            table[tempt] = true;
        }   
    }
    
    for(auto i : table)
    {
        if(i)
            answer++;
    }
    
    return answer;
    
}