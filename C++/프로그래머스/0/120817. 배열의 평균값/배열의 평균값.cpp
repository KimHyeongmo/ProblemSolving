#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    
    int index = numbers.size();
    double answer = 0;
    for(int i = 0; i<index; i++)
    {
        answer += numbers[i];
    }
    answer/=index;

    return answer;
}