#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int total = phone_number.length();
    for(int i = 0; i<total - 4; i++)
    {
        phone_number[i] = '*';   
    }
    return phone_number;
}