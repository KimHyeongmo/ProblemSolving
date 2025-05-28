#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int initial = x;
    int value = 0;
    
    while(x > 0)
    {
        value += (x%10);
        x /= 10;
    }
    if(0 == initial%value)
    {
        return true;
    }
        
    return false;
}