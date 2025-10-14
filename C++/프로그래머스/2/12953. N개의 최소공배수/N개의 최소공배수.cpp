#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if(b > a)
    {
        int t = a;
        a = b;
        b = t;
    }
    
    int r = a % b;
    
    if(r == 0)
    {
        return b;
    }
    else
    {
        return GCD(b, r);
    }
}

int LCM(int a, int b)
{
    int gcd = GCD(a, b);
    
    return a * b / gcd;
}

int solution(vector<int> arr) {
    
    int answer = arr[0];
    
    for(auto i = arr.begin() + 1; i < arr.end(); i++)
    {
        answer = LCM(answer, *i);
    }
    
    return answer;
}