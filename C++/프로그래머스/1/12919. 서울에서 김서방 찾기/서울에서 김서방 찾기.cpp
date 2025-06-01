#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string answer2 = "에 있다";
    
    for(int i = 0; i<seoul.size(); i++)
    {
        if(seoul[i].compare("Kim") == 0)
        {
            answer.append(to_string(i));
            answer.append(answer2);
            return answer;
        }
    }
}