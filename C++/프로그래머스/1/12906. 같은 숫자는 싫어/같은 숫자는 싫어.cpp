#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int val = -1;
    
    for(auto each : arr)
    {
        if(val != each)
        {
            val = each;
            answer.push_back(val);
        }
    }

    return answer;
}