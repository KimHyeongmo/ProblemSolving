#include <string>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto i = my_string.rbegin(); i != my_string.rend(); i++)
    {
        answer.push_back(*i);
    }
    return answer;
}