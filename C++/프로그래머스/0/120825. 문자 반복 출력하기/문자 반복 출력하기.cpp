// +4점 나옴 ㄷㄷ
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int index = my_string.length();
    string tempt(n, ' ');
    
    for(int i = 0; i<index; i++)
    {
        for(int j = 0; j<n; j++)
        {
            tempt[j] = my_string[i];
        }
        answer.append(tempt);
    }
    
    return answer;
}