#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer;
    n /= 2;
    answer = n * (1 + n);
    return answer;
}