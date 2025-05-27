#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto i = my_string.begin(); i != my_string.end(); i++)
    {
        switch(*i)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default :     
                answer.push_back(*i);
        }
    }
    return answer;
}