// 아랫자리부터 시작하여 연속된 1이 끝나는 가장 적은 자릿수 지점을 1로 바꾸고, 그 아랫자리수는 0으로 모두 바꾼뒤,
// 아래에서부터 n-1의 개수만큼 1을 채워준다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int origin = n;
    int answer = n;
    int count = 0;
    
    vector<int> binary;
    
    while(n != 0)
    {
        binary.push_back(n%2);
        n/=2;
    }
    
    bool check = false;
    int index = -1;
    
    for(int i = 0; i<binary.size(); i++)
    {
        if(!check)
        {
            if(binary[i] == 1)
            {
                check = true;
                index = i;
                count++;
            }
        }
        else
        {
            if(binary[i] == 1)
            {
                index = i;
                count++;
            }
            else
                break;
        }
    }
    
    origin >>= (index+1);
    origin <<= (index+1);
        
    origin += (1 << (index+1));
    
    int tempt = 0;
    
    for(int i = 0; i < count - 1; i++)
    {
        tempt = tempt + (1 << i);
    }
    
    origin += tempt;
        
    return origin;
}