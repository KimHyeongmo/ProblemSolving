//sizeof로는 배열에 대하여 전체 실제 "크기"로 비교
//c++의 size로는 vector에 대하여 각 차원에 대하여 엘리먼트의 "갯수"를 셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int rowIndex = arr1.size();
    int columnIndex = arr1[0].size();
    
    for(int i = 0; i<rowIndex; i++)
    {
        answer.push_back(vector<int>());
        for(int j = 0; j<columnIndex; j++)
        {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    
    return answer;
}