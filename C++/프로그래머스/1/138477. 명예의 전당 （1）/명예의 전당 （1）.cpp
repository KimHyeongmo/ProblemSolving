#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
        
    int i = 0;
    for(i; i<k; i++)
    {
        if(i >= score.size())
            return score;
        pq.push(score[i]);
        score[i] = pq.top();
    }
    int top, cur;
    for(i; i<score.size(); i++)
    {
        top = pq.top();
        cur = score[i];
        if(top < cur)
        {
            pq.pop();
            pq.push(cur);
            score[i] = pq.top();
        }
        else if(top >= cur)
        {
            score[i] = top;
        }
    }

    return score;
}