#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
vector<pii> t;
vector<int> A, B;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        int b; 
        cin >> b;
        B.push_back(b);
    }
    for(int i = 0; i < n; i++) t.emplace_back(A[i], B[i]);
    sort(t.begin(), t.end());

    priority_queue<int> q;
    int pre = t[0].first;
    long long res = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i;
        while(j < n && t[j].first == pre)
        {
            q.push(t[j].second);
            sum += t[j].second;
            j++;
        }

        sum -= q.top();
        q.pop();
        res += sum;
        if(q.empty()) pre = t[j].first;
        else pre++;

        i = j - 1;
    }
    while(!q.empty())
    {
        sum -= q.top();
        q.pop();
        res += sum;
    }
    
    cout << res;

    return 0;
}