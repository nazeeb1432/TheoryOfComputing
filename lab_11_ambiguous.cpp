#include <bits/stdc++.h>
using namespace std;

int path_way = 0;
string path;
vector<string>paths,paths2;

void cfg(vector<string> &productions, string output, string target, string currpath)
{
    if (path_way>=2)
        return;

    if (output.size()>target.size()+2)
        return;

    if (output.find('S')==string::npos && output!=" ")
    {
        if (output==target)
        {
            path_way++;
            path = currpath;
            paths.push_back(path);//ultimately,(->as->aaSbS->aabS->aab)eta pushback hobe
        }
        return;
    }

    for (string x : productions)
    {
        if (output.find('S')!=string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;//aaS
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cfg(productions, x, target, currpath+"->"+x);
        if (path_way>=2)
            return;
    }
}



int main()
{
    vector<string> productions = {"aS", "aSbS", ""};
    string s;
    cout<<"Enter string:";
    cin >> s;
    cfg(productions, " ", s, path);//vector<string> &productions, string output, string target, string currpath

    if(path_way==2)
    {
        for(string x : paths)
        cout<<"Letfmost : S"+x<<endl;
        cout<<"The grammar is ambiguous"<<endl;
    }
    else
    cout<<"May not be ambiguous"<<endl;

    return 0;
}