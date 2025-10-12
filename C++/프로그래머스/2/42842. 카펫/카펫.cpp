#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    
    
    int area = yellow + brown;
    int row = 1;
    
    while(true)
    {
        if(area % row == 0)
        {
            int sum_colum_row = area / row + row;
            if(sum_colum_row == (brown / 2 + 2) && sum_colum_row == ((area - yellow + 4) / 2))
                break;
        }
        row++;
    }
    
    answer.push_back(area / row);
    answer.push_back(row);
    
    return answer;
}

/*
    2n + 2m - 4 = brown,
    n + m = brown/2 + 2,
    
    nm - 2(n+m) + 4 = yellow,
    
    (nm - yellow + 4)/2 = (n+m);
    
    nm = yellow + brown,
    
    2n+2(m-2) == brown,
    (n-2) * (m-2) == yellow,
    */