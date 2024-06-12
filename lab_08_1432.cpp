#include<bits/stdc++.h>
using namespace std;

string w, x, y, z, s,s1,s2;
int r1,r2;
set<string> st;
string reg_exp;
int n, l, whichK;

void generateString(string &s, int n);
bool verifyString();
bool checkIfStringIsInTheLanguage(string &s);
void extract_ratio(string &s1, string&s2);
int char_to_int(string &s);
int generateSeparator();
int generateN();

int main(){
    //freopen("p_lemma.txt", "r", stdin); // for 0^n1^2n
    freopen("p_lemma2.txt", "r", stdin); // for 0^n1^n
    cin >> reg_exp;
    int i;
    cout << "Regular Expression: " << reg_exp << endl;
    
    //parse regex
    for(i = 0; i < reg_exp.size();++i){
        if(reg_exp[i] == '0' and reg_exp[i+1] == '^'){
            i++;
            break;       
        }
    }
    
    while(reg_exp[++i] != '^'){
        s1+=reg_exp[i];
    }

    if(s1[s1.size()-1] == '1') s1.resize(s1.size()-1);
    //i++;
    //cout << endl << reg_exp[i] << endl << endl;
    while(reg_exp[++i]!='\0'){
        s2+=reg_exp[i];
    }
    
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;  
    extract_ratio(s1,s2);
    cout << "ratio1, r1 == " <<  r1 << endl << "ratio2, r2 == " << r2 << endl;
    //0^n1^n
    //cin >> n;
    n = generateN();
    cout << "n = " << n << endl;
    generateString(w, n);
    cout << "String, w: " << w << endl;
    //cin >> l; //l<=n  && |xy| = n
    l = generateSeparator();
    cout << "Separator, l = " << l << endl;
    // (0000)(0000)"1111111111111111"
    //   x      y            z
    if(l != n){
        for(int i = 0; i < l; ++i) x += w[i];
        for(int i = l; i < n; ++i) y += w[i];
        for(int i = n; i < w.size(); ++i) z+=w[i];
    }//below is the logic for, y cannot be of length zero
    else if(l == n){
        for(int i = 0; i < l-1; ++i) x += w[i];
        for(int i = l-1; i < n; ++i) y += w[i];
        for(int i = n; i < w.size(); ++i) z+=w[i];
    }

    cout << "x: " << x << " y: " << y << " z: " << z<< endl;
    verifyString() ? cout << "The string is also in the language" << endl : cout << "The string is not in the language for k = " << whichK << endl;
    return 0;
}

void generateString(string &w, int n){
    int i;
    int length = (r1 + r2) * n;
    cout << "Length of w = (" << r1 << " + " << r2 << ") * " << n <<  " = " << length << endl;
    for(i = 0; i < length ;++i){
        if(i < r1*n) w+='0'; // 0 1 2 3 4 5 6 7
        if(i >= r1*n) w+='1'; //8 ...... 15
    }
}

bool verifyString(){
    int k = 0;
    bool check;
    while(1){
        s+=x;
        for(int i = 1; i <= k; ++i) s+=y;
        s+=z;
        //s -> xy^kz
        cout << "s: " << s << endl;
        check = checkIfStringIsInTheLanguage(s);
        if(check == false){
            whichK = k;
            break;
        } 
        s.clear();
        k++;
    }
    if(check == false) return false;
    return true;
}

bool checkIfStringIsInTheLanguage(string &s){
    int countZero = 0, countOne = 0;
    for(int i =0; i< s.size(); ++i){
        if(s[i] == '0') countZero++;
        else countOne++;
    } 
    return (r2 * countZero) == (r1 * countOne); // r1/r2 = c0/c1
}


void extract_ratio(string &s1, string&s2){
    string tmp1,tmp2;
    for(int i = 0; i < s1.size();++i){
        if(s1[i] == 'n'){
            int j = i-1;
            while(j>=0){
                tmp1+=s1[j];
                j--;
            }
        }
    }
    reverse(tmp1.begin(), tmp1.end());
    cout << "tmp1 == "<< tmp1<< endl;
    
    for(int i = 0; i < s2.size();++i){
        if(s2[i] == 'n'){
            int j = i-1;
            while(j>=0){
                tmp2+=s2[j];
                j--;
            }
        }
    }
    reverse(tmp2.begin(), tmp2.end());
    cout << "tmp2 == " << tmp2 << endl;
    if(tmp1.size() == 0) r1=1;
    else r1 = char_to_int(tmp1);
    if(tmp2.size() == 0) r2=1; 
    else r2 = char_to_int(tmp2);
}

int char_to_int(string &s){
    char tmp[3];
    for(int i = 0; i < s.size(); ++i) tmp[i] = s[i];
    int num = atoi(tmp);
    return num;
} 

int generateN(){
    srand(time(0));
    int n = rand() % 5 + 1;
    return n;
}

int generateSeparator(){
    srand(time(0));
    int randomSeparator = rand() % n;
    return randomSeparator; 
}

// n -> 10
// l -> 10
// 0^2n1^n

/*

    0^2n1^3n
    n <- 2
    w = 0000 111111
    countZero = 4
    countOne = 6
    r1 <- 2
    r2 <- 3
    3*4 = 2*6

*/