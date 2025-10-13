#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> group;
    
    for(int i : tangerine)
    {
        if(group.find(i) == group.end())
        {
            group.insert(make_pair(i, 0)); 
        }
            
        group[i]++;
    }
    
    vector<pair<int,int>> vec(group.begin(), group.end());
    
    sort(vec.begin(), vec.end(), compare);
    
    for(pair<int, int> each : vec)
    {
        k -= each.second;
        answer++;
        if(k <= 0)
            break;
    }
    
    
    return answer;
}