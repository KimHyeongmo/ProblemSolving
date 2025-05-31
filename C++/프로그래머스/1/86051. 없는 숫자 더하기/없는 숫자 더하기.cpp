#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    unsigned int bitmask = 0;
    for(auto i : numbers)
    {
        int j = 1;
        j <<= i;
        bitmask += j;
    }
    for(int i = 0; i<10; i++)
    {
        if(((bitmask >> i) & 1) != 1)
        {
            answer += i;
        }
    }
    
    return answer;
}