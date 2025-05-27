#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int big = 0;
    int small = 0;
    for(auto i = numbers.begin(); i != numbers.end(); i++)
    {
        if(*i > big)
        {
            small = big;
            big = *i;
        }
        else if(*i > small)
        {
            small = *i;
        }
    }
    return small * big;
}