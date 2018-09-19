#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <set>
#define MAX 507

using namespace std;

//大写字母为非终止符(可以多一个'的标号做区分)，小写字母为终止符,用~代替epsilon
class WF
{
  public:
    string left;
    set<string> right;
    WF(char s[])
    {
        left = s;
    }
    void print()
    {
        printf("%s->", left.c_str());
        set<string>::iterator it = right.begin();
        if (right.begin() != right.end())
        {
            printf("%s", it->c_str());
            it++;
        }
        for (; it != right.end(); it++)
            printf("|%s", it->c_str());
        puts("");
    }
    void insert(char s[])
    {
        right.insert(s);
    }
};

map<string, set<char>> first;
map<string, set<char>> follow;
map<string, int> VN_dic;
vector<WF> VN_set;
bool used[MAX];

void dfs(int x)
{
    if (used[x])
        return;
    used[x] = 1;
    string &left = VN_set[x].left;
    set<string> &right = VN_set[x].right;
    set<string>::iterator it = right.begin();
    for (; it != right.end(); it++)
        for (int i = 0; i < it->length(); i++)
        {
            if (!isupper(it->at(i)) && it->at(i) != '\'')
            {
                first[left].insert(it->at(i));
                break;
            }
            if (isupper(it->at(i)))
            {
                int y;
                if (i != it->length() - 1 && it->at(i + 1) == '\'')
                    y = VN_dic[it->substr(i, 2)] - 1;
                else
                    y = VN_dic[it->substr(i, 1)] - 1;
                string &tleft = VN_set[y].left;
                dfs(y);
                set<char> &temp = first[tleft];
                set<char>::iterator it1 = temp.begin();
                bool flag = true;
                for (; it1 != temp.end(); it1++)
                {
                    if (*it1 == '~')
                        flag = false;
                    first[left].insert(*it1);
                }
                if (flag)
                    break;
            }
            else
                continue;
        }
}

void make_first()
{
    memset(used, 0, sizeof(used));
    for (int i = 0; i < VN_set.size(); i++)
        dfs(i);
#define DEBUG
#ifdef DEBUG
    map<string, set<char>>::iterator it = first.begin();
    for (; it != first.end(); it++)
    {
        printf("FIRST(%s)={", it->first.c_str());
        set<char> &temp = it->second;
        set<char>::iterator it1 = temp.begin();
        bool flag = false;
        for (; it1 != temp.end(); it1++)
        {
            if (flag)
                printf(",");
            printf("%c", *it1);
            flag = true;
        }
        puts("}");
    }
#endif
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    char s[MAX];
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            int len = strlen(s), j;
            for (j = 0; j < len; j++)
                if (s[j] == '-')
                    break;
            s[j] = 0;
            if (!VN_dic[s])
            {
                VN_set.push_back(s);
                VN_dic[s] = VN_set.size();
            }
            int x = VN_dic[s] - 1;
            VN_set[x].insert(s + j + 2);
        }
        make_first();
    }
}