#include<bits/stdc++.h>
using namespace std;
string generateString(int n,string lemma,int mul_z,int mul_o){
    string str = "";
    for(int i=0; i<mul_z*n; i++){
        str += "0";
    }
    for(int i=0; i<mul_o*n; i++){
        str += "1";
    }
    return str;
}
string pump(string x,string y, string z,int k){
    string str = "";
    str.append(x);
    for(int i=0; i<k; i++){
        str.append(y);
    }
    str.append(z);
    return str;
}
bool inLanguage(string str,int n,int mul_z,int mul_o){
    string zero = "",one = "";
    int i;
    for(i=0; i<str.size(); i++){
        if(str[i] == '0')zero += "0";
        else break;
    }
    while(i < str.size()){
        if(str[i] == '1')one += "1";
        else break;
        i++;
    }
    if((zero.size() + one.size() == str.size()) and (zero.size() == n*mul_z) and (one.size() == n*mul_o))return true;
    return false;
}
int multiplier(string str){
    int i;
    if(str[0] == 'n')return 1;
    for(i=0; i<str.size(); i++){
        if(str[i] == 'n')break;
    }
    int x = stoi(str.substr(0,i));
    return x;
}
int main(){
    srand(time(0));
    string lemma;
    cout << "Enter the lemma: ";
    getline(cin,lemma);
    string a = "",b = "";
    int i;
    for(i=0; i<lemma.size(); i++){
        if(lemma[i] == '^'){
            i++;
            while(lemma[i] != ' '){
                a.push_back(lemma[i]);
                i++;
            }
            break;
        }
    }
    for(; i<lemma.size(); i++){
        if(lemma[i] == '^'){
            i++;
            while(lemma[i]){
                b.push_back(lemma[i]);
                i++;
            }
            break; 
        }
    }
    // 0^2n 1^3n
    int mul_z,mul_o;
    mul_z = multiplier(a);
    mul_o = multiplier(b);
    cout << mul_z << " " << mul_o << endl << endl;
    int n = rand() % 12 + 4;
    string inputString = generateString(n,lemma,mul_z,mul_o);
    cout << "input -> " << inputString << endl << endl;
    int k = 1;
    bool regular = true;
    while(true){
        int a,b,c;
        a = n/2;
        b = n/2-1;
        string x = inputString.substr(0,a);
        string y = inputString.substr(a,b);
        string z = inputString.substr(a+b,inputString.size()-a-b);
        cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl << endl;
        string pumped = pump(x,y,z,k);
        cout << "pumped->" << pumped << endl << endl;
        if(!inLanguage(pumped,n,mul_z,mul_o)){
            regular = false;
            break;
        }
        k++;
    }
    if(!regular)cout << "The language is not regular" << endl;
    return 0;
}