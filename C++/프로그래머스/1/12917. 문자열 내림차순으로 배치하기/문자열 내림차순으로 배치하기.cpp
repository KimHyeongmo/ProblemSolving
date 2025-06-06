#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> stoi;
    for(auto i : s)
    {
        //우선순위 큐로 안되나?
        stoi.push_back(static_cast<int>(i));
    }
    
    sort(stoi.rbegin(), stoi.rend());
    
    for(auto i : stoi)
    {
        answer.push_back(i);
    }
    
    return answer;
}