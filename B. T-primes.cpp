#include <iostream>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

const int N = 1000010;
bool st[N];
int a[N];

int main()
{
    set<long long> h;

    for(int i = 2; i < N; i++)
    {
        if(!st[i])
        {
            long long t = (long long)i  * i;
            h.insert(t);
            for(int j = i + i; j < N; j += i)
                st[j] = 1;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if(h.count(a) != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}