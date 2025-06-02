//인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.
//해당 조건에 의해 같은 값은 없음

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int index = 0;
    int small = arr[0];
    
    for(int i = 1; i<arr.size(); i++)
    {
        if(arr[i] < small)
        {
            index = i;
            small = arr[i];
        }
    }
    
    arr.erase(arr.begin() + index);
    
    
    if(arr.size() == 0)
    {
        return vector<int>(1,-1);
    }
    
    return arr;
}