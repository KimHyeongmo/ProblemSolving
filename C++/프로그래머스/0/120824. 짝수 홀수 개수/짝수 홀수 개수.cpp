#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2);
    vector<int>::iterator i;
    for(i = num_list.begin(); i != num_list.end(); i++)
    {
        if(0 == *i % 2)
            answer[0]++;
        else
            answer[1]++;
    }
    return answer;
}