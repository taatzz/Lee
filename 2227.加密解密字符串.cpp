#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Encrypter {
public:
    unordered_map<char, int> k_v;
    unordered_map<int, string> v_k;
    unordered_map<string, vector<int>> t;
    unordered_map<string, int> h;
    vector<string> d;

    void init()
    {
        for(auto& s : d)
        {
            string res;
            for(int i = 0; i < s.size(); i++)
            {
                if(!k_v.count(s[i]))
                {
                    res = "";
                    break;
                }
                int x = k_v[s[i]];
                res += v_k[x];
            }
            h[res]++;
        }
    }

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++) k_v[keys[i]] = i;
        d = dictionary;
        for(int i = 0; i < values.size(); i++) 
        {
            v_k[i] = values[i];
            t[values[i]].push_back(i);
        }
        init();
    }
    
    string encrypt(string s) {
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            int x = k_v[s[i]];
            res += v_k[x];
        }

        return res;
    }
    
    int decrypt(string s) {
        return h.count(s) ? h[s] : 0;
    }
};
/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */