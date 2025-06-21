//문자열에서 가장 왼쪽 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minRow = 50;
    int minCol = 50;
    int maxRow = -1;
    int maxCol = -1;

    for(int i = 0; i<wallpaper.size(); i++)
    {
        bool check = false;
        
        int tMinCol = 50;
        int tMaxCol = -1;
        
        for(int j = 0 ;j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                check = true;
                
                if(j < tMinCol)
                    tMinCol = j;
                tMaxCol = j;
            }
        }
        
        if(tMinCol < minCol)
            minCol = tMinCol;
        if(tMaxCol > maxCol)
            maxCol = tMaxCol;
        
        if(check)
        {
            if(i < minRow)
                minRow = i;
            maxRow = i;
        }
    }
    
    answer.push_back(minRow);
    answer.push_back(minCol);
    answer.push_back(maxRow + 1);
    answer.push_back(maxCol + 1);
    
    return answer;
}