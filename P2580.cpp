#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Trie
{
public:
    class TrieNode
    {
    public:
        bool st;
        TrieNode* son[26];
    };

    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        for(int i = 0; i < 26; i++)
        {
            if(!root->son[i]) delete(root->son[i]);
        }
    }

    void insert(string s)
    {
        TrieNode* p = root;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!p->son[u]) p->son[u] = new TrieNode();
            p = p->son[u];
        }
        p->st = true;
    }

    bool query(string s)
    {
        TrieNode* p = root;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!p->son[u]) return 0;
            p = p->son[u];
        }

        return p->st;
    }
};

int main()
{
    int n;
    cin >> n;
    
    Trie son;
    unordered_set<string> h;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        h.insert(s);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int st = son.query(s);
        if(!h.count(s)) cout << "WRONG" << endl;
        else
        {
            if(st) cout << "REPEAT" << endl;
            else
            {
                cout << "OK" << endl;
                son.insert(s);
            }
        }
    }

    return 0;
}