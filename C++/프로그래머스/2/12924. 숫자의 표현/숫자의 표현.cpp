#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    bool check = true;
    
    //capacity 채워두기
    vector<int> num(n);
    
    int R = n;
    int L = n;
    
    while(check)
    {
        num.clear();
        int sum = 0;
        for(int i = R; i>=L; i--)
        {
            num.push_back(i);
        }
        for(auto i : num)
        {
            sum += i;
        }
        
        R--;
        L--;
        
        if(sum == n)
        {
            answer++;
            L--;
        }
        if(sum < n)
        {
            R++;
        }
        
        if(L <= 0)
            check = false;   
    }
    
    return answer;
}