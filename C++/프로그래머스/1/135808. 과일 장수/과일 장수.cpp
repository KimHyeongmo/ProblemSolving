//높은 것부터 넣고, 현재 갯수만큼 나누면서 이전 값보다 크고, 다음 값보다 클 때 그 순간 멈춘다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.rbegin(), score.rend());
    
    for(int i = 0; i<score.size();)
    {
        int j = i;
        i += (m - 1);
        if(i >= score.size())
            break;        
        int t = score[i];
        answer += (t * (i - j + 1));

        i++;
    }
    
    
    return answer;
}