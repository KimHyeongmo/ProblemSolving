//알파벳 26자

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = vector<int>(s.size(), -1);
    vector<int> alphabetContainer = vector<int>(26, -1);
    
    for(int i = 0; i<s.size(); i++)
    {
        int num = static_cast<int>(s[i]) - 'a';
        if(alphabetContainer[num] == -1)
        {
            alphabetContainer[num] = i;
            answer[i] = -1;
            continue;            
        }
        answer[i] = i - alphabetContainer[num];
        alphabetContainer[num] = i;
    }
    
    return answer;
}