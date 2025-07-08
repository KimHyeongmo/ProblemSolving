//스택으로 한다.
#include<stack>
#include<string>
using namespace std;

int solution(string s)
{   
    stack<char> pocket;
    pocket.push('0');
    
    for(auto i : s)
    {
        if(pocket.top() != i)
        {
            pocket.push(i);
        }
        else
        {
            pocket.pop();
        }
    }
    
    if(pocket.size() == 1)
        return 1;
    else
        return 0;
}