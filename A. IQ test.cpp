#include <iostream>

using namespace std;

const int N = 110;
int a[N];

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int odd_num = 0, even_num = 0, odd_last = 1, even_last = 1;

    for(int i = 1; i <= n; i++)
    {
        if(a[i] % 2)
        {
            odd_num++;
            odd_last = i;
        }
        else 
        {
            even_num++;
            even_last = i;
        }
    }

    if(odd_num == 1) cout << odd_last << endl;
    else cout << even_last << endl;

    return 0;
}