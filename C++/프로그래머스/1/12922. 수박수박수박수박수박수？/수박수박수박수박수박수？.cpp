#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int subak = n/2;
    int su = n%2;
    for(int i = 0; i<subak; i++)
    {
        answer += "수박";
    }
    if(su == 1)
    {
        answer += "수";
    }
    return answer;
}