#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> database;

    while(n --)
    {
        string s;
        cin >> s;
        if(database.find(s) == database.end())
        {
            cout << "OK" << endl;
            database[s] ++;
        }
        else
        {
            string tmp = s + to_string(database[s]);

            cout << tmp << endl;

            database[s]++;
        }
    }

    return 0;
}