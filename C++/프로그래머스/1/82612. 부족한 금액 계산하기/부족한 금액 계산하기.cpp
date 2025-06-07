using namespace std;

long long solution(int price, int money, int count)
{
    count = (count * count + count) / 2;
    long long totalPrice = (long long)price * count;
    if(totalPrice > money)
    {
        return totalPrice - money;
    }
    else
        return 0;
}