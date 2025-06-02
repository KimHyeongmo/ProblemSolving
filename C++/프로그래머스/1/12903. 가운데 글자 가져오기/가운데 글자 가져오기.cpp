#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = s.length();
    if(index % 2 == 0)
    {
        index = s.length()/2;
        answer.push_back(s[index-1]);
        answer.push_back(s[index]);
    }
    else
    {
        index = s.length()/2;
        answer.push_back(s[index]);
    }
    
    return answer;
}