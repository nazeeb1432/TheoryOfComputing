#include<bits/stdc++.h>
using namespace std;

vector<string> productions = {
    "aS",
    "aSbS",
    "e"
};

vector<char> terminals = {'a', 'b'};
string derivation = "S";
string s;
string startingProduction;//aS or aSbS

int countB(string &derivation);
bool isAmbigous();
int countS(string &derivation);

int main(){
    freopen("lab_11_input.txt", "r", stdin);
    cin >> s;
    cout << "Leftmost 1: ";
    startingProduction = productions[0];// aS     
    cout << derivation << " => ";
    
    derivation = startingProduction;

    for(int i = 1; i < s.size(); ++i){
        cout << derivation << " => ";
        int cntB = 0;
        if(s[i] == 'a' and ( s.size() - i > 1 ) and cntB < 2){
            int idx = derivation.find('S');
            derivation = derivation.substr(0,idx) + "aSbS" + derivation.substr(idx+1);
            cntB = countB(derivation);
        }
        if(s[i] == 'b' and ((cntB < 2) or (i == s.size()-1))){
            
            int cntS = countS(derivation);
            for(int i = 1; i<= cntS; ++i){
                int idx = derivation.find('S');
                derivation = derivation.substr(0,idx) + derivation.substr(idx+1);
                if(i != cntS) cout << derivation << " => ";
                else cout << derivation;
            }
        }
    }
    cout << endl;

    cout << "Leftmost 2: ";
    startingProduction = productions[1];     
    cout << "S => ";
    derivation = startingProduction;
    
    for(int i = 1; i < s.size(); ++i){
        cout << derivation << " => ";
        int cntB = 0;
        if(s[i] == 'a' and ( s.size() - i > 1 ) and cntB < 2){
            int idx = derivation.find('S');
            derivation = derivation.substr(0,idx) + "aS" + derivation.substr(idx+1);
            cntB = countB(derivation);
        }
        if(s[i] == 'b' and ((cntB < 2) or (i == s.size()-1))){
            
            int cntS = countS(derivation);
            for(int i = 1; i<= cntS; ++i){
                int idx = derivation.find('S');
                derivation = derivation.substr(0,idx) + derivation.substr(idx+1);
                if(i != cntS) cout << derivation << " => ";
                else cout << derivation;
            }
        }
    }
    cout << endl;
    isAmbigous() ? cout << "The Grammer is ambiguous" << endl: cout << "The Grammer is not ambiguous" << endl;
    return 0;
}

bool isAmbigous(){
    int cnt_arr[terminals.size()];
    for(int i = 0; i < terminals.size(); ++i) cnt_arr[i] = 0;
    for(int i = 0; i < productions.size();++i){
        char firstChar = productions[i][0];
        if(firstChar == terminals[0] || firstChar == terminals[1]){
            cnt_arr[firstChar - 'a']++;
        }
    }
    for(int i = 0; i < terminals.size(); ++i){ 
        // cout << element << " ";
        if(cnt_arr[i] > 1) return true;  
    } 
    return false;
}

int countB(string &derivation){
    int cnt = 0;
    for(int i = 0; i < derivation.size(); ++i){
        if(derivation[i] == 'b') cnt++;
    }
    return cnt;
}

int countS(string &derivation){
    int cntS = 0;
    for(int i = 0; i < derivation.size(); ++i) if(derivation[i] == 'S') cntS++;
    return cntS;
}