#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int beforeGainScore = 0;
    int currentGainScore = 0;
    for(int i = 0; i<dartResult.size(); i++)
    {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            answer += beforeGainScore;
            
            beforeGainScore = currentGainScore;
            
            currentGainScore = dartResult[i] - '0';
            
            if(i+1 < dartResult.size())
            {
                if(dartResult[i] == '1' && dartResult[i+1] == '0')
                {
                    i++;
                    currentGainScore = 10;
                }
            }
        }
        else if(dartResult[i] == '*')
        {
            beforeGainScore *= 2;
            currentGainScore *= 2;
        }
        else if(dartResult[i] == '#')
        {
            currentGainScore = -currentGainScore;
        }
        else if(dartResult[i] == 'S')
        {
            currentGainScore = currentGainScore;
        }
        else if(dartResult[i] == 'D')
        {
            currentGainScore = currentGainScore * currentGainScore;
        }
        else if(dartResult[i] == 'T')
        {
            currentGainScore = currentGainScore * currentGainScore * currentGainScore;
        }
    }
    
    answer = answer + beforeGainScore + currentGainScore;
    
    return answer;
}