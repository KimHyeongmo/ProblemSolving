#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//풀이 아이디어를 참고함.
//정렬하여 가장 큰 수와 가장 작은 수를 묶어 가며 limit에 도달하는 지 확인하고, 가장 큰 수 포인터를 좌측으로 이동해 가면 됨.
//이게 되는 이유가, 가장 큰 수와 가장 작은 수보다 더 큰 수를 합해도 limit에 도달하지 않더라도 그 두개를 묶을 이유가 없는게
//어차피 그 더 큰 수와 가장 큰 수보다 조금 더 작은 수를 합해도 limit에 절대 도달하지 않을 것이기 때문.
//따라서 매 순간 만족하는 한 쌍을 만들어가면 되고
//설령 가장 큰 수보다 작은 수의 쌍이 그 전의 쌍으로 인해 기회가 사라지더라도, 그냥 가장 큰 수를 소모했기 때문에
//대신 희생되었다고 보면 됨.

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    
    int minP = 0;
    int maxP = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while(minP < maxP)
    {
        int sum = people[minP] + people[maxP];
        if(sum <= limit)
        {
            answer++;
            minP++;
            maxP--;
        }
        else
        {
            answer++;
            maxP--;
        }   
    }
    
    //개념적으론 따로 빼는게 적절함. 아마 돌아가는 것 자체는 위의 비교문에서 포함 시켜도 되긴 할텐데..
    if(minP == maxP)
    {
        answer++;        
    }
    
    
    return answer;
}

/* 최초 시도

//로직은 맞는데, 시간이 문제임.
//순회 한번 하는 김에 한꺼번에 할 수는 없나?

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    for(int i = 0; i<people.size(); i++)
    {
        if(people[i] != -1)
        {   
            answer++;
            int currentMax = people[i];
            int currentIndex = -1;
            for(int j = i + 1; j < people.size(); j++)
            {
                int sum = people[i] + people[j];
                if(limit >= sum && sum > currentMax)
                {
                    currentMax = sum;
                    currentIndex = j;
                }
                if(sum == limit)
                    break;
            }
            people[i] = -1;
            if(currentIndex != -1)
                people[currentIndex] = -1;
            
        }
    }
    
    return answer;
}

*/