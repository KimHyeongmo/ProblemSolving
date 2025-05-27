#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(true)
    {
        long long i = n/10;
        int j = n%10;

        if((i+j)<=0)
            break;
        
        answer.push_back(j);
        
        n = i;
    }
    return answer;
}