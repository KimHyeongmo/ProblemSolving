#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    if(s.size() != 4 && s.size() != 6)
        return false;
    
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] > 64)
            return false;
    }
    
    return true;
}