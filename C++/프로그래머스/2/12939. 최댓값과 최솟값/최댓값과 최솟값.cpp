#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    auto i = s.begin();
    string snumber_init = "";
    while((*i != ' ') && (i != s.end()))
    {
        snumber_init.push_back(*i);
        i++;
    }
    int number_init = stoi(snumber_init);
    int small = number_init;
    int max = number_init;

    while(i != s.end())
    {
        i++;
        string snumber = "";
        while((*i != ' ') && (i != s.end()))
        {
            snumber.push_back(*i);
            i++;
        }
        int number = stoi(snumber);
        
        if(number < small)
        {
            small = number;
        }
        if(number > max)
        {
            max = number;
        }
    }
    
    answer = answer + to_string(small) + " " + to_string(max);
    
    
    return answer;
}