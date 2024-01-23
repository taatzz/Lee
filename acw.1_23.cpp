#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long res = 0;
    for(long long i = 2; i <= n / i; i++)
    {
        if(n % i == 0)
        {
            res ++;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res++;

    cout << res << endl;

    return 0;
}