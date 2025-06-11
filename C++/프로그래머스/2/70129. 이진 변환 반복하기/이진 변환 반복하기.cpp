#include <string>
#include <vector>

using namespace std;

int NoZeroBinary(string s, string& newS)
{
    newS.clear();
    int count = 0;
    int oneCount = 0;
    for(auto i : s)
    {
        if(i == '1')
        {
            oneCount++;
        }
        else
        {
            count++;
        }
    }
    vector<int> d;
    
    //정수를 이진수 문자열로 바꾸기
    while(oneCount != 1)
    {
        d.push_back(oneCount % 2);
        oneCount /= 2;
    }
    d.push_back(1);
    
    for(auto i = d.rbegin(); i != d.rend(); i++)
    {
        newS.push_back(static_cast<char>(*i+'0'));
    }
    
    return count;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    string newS;
    int count = 0;
    int count2 = 0;
    while(true)
    {
        count += NoZeroBinary(s, newS);
        s = newS;
        count2++;
        if(s.size() <= 1)
        {
            break;
        }
    }
    answer[0] = count2;
    answer[1] = count;
    
    return answer;
}