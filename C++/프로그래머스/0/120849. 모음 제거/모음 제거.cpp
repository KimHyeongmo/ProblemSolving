#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto i = my_string.begin(); i != my_string.end(); i++)
    {
        if(*i == 'a')
            continue;
        else if(*i == 'e')
            continue;
        else if(*i == 'i')
            continue;
        else if(*i == 'o')
            continue;
        else if(*i == 'u')
            continue;
        
        answer.push_back(*i);
    }
    return answer;
}