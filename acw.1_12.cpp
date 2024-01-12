#include <iostream>
#include <string>

using namespace std;

const int N = 1000010;
int f[N][2];

int main()
{
    string a;
    cin >> a;
    int n = a.size();

    f[0][0] = 0;
    f[0][1] = a[0] - 'a' + 1;

    for(int i = 1; i < a.size(); i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = max(f[i][1], f[i - 1][0] + a[i] - 'a' + 1);
    }

    cout << max(f[n - 1][0], f[n - 1][1]);

    return 0;
}