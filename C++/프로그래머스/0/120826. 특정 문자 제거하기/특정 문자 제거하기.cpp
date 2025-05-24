#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    string::iterator i;
    for(i = my_string.begin(); i != my_string.end(); i++)
    {
        if(letter[0] != *i)
        {
            answer.push_back(*i);
        }
    }
    return answer;
}