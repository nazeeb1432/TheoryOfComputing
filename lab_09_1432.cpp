#include <bits/stdc++.h>
using namespace std;

vector<string> derivations;
string str;

void print_derivations();

int main()
{
    freopen("lab_09.txt", "r", stdin);
    cin >> str;
    derivations.push_back("P");
    int i;
    
    if(str.size() == 1){
        cout << derivations[0] << " => ";
        cout << str[0] << endl;
        return 0;
    }else{
        string initial_derivation;
        initial_derivation = str[0] + derivations[0] + str[0];
        derivations.push_back(initial_derivation);
        
        for (i = 1; i < str.size() / 2; ++i){
            string temp, substr1, substr2;
            substr1 = derivations[i].substr(0, (derivations[i].size() / 2));
            substr2 = derivations[i].substr((derivations[i].size() / 2) + 1);
            temp = substr1 + str[i] + 'P' + str[i] + substr2;
            derivations.push_back(temp);
        }
        string temp;
        temp = derivations[derivations.size() - 1];//latest one in derivation
        if (str.size() % 2 == 1){//if odd
            temp[temp.size() / 2] = str[str.size() / 2];
        }else{
            string substr1, substr2;
            substr1 = temp.substr(0, (temp.size() / 2));
            substr2 = temp.substr((temp.size() / 2) + 1);
            temp = substr1 + substr2;
        }
        derivations.push_back(temp);
    }
    print_derivations();
    return 0;
}

void print_derivations(){
    if (str != derivations[derivations.size() - 1]){
        cout << "Not in the grammar" << endl;
        return;
    }else{
        cout << derivations[0];
        for (int i = 1; i < derivations.size(); ++i) cout << " => " << derivations[i];
        cout << endl;
    }
}