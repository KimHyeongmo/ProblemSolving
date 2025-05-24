#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        k = i*i;
        if(k == n)
        {
            return 1;
        }
        if(k > n)
        {
            return 2;
        }
    }

    return 2;
}