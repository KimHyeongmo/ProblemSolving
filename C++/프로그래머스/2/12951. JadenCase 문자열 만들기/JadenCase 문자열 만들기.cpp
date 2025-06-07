#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    bool check = true;
    for(int i = 0; i<s.size(); i++)
    {
        if(check && (s[i] >= 'a'))
        {
            check = false;
            s[i] -= 32;
            continue;
        }
        if(s[i] == ' ')
        {
            check = true;
            continue;
        }
        if(!check && s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
        check = false;
    }
    
    return s;
}