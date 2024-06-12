#include<bits/stdc++.h>
using namespace std;

string input, startingProduction, tmp;

void printTransition(string &tmp);

int main(){
    //freopen("cfg.txt", "r", stdin);
    cout << "Enter your input: ";
    cin >> input;
    startingProduction = "A1B";
    cout << "Leftmost: ";
    cout << "S => " << startingProduction;
    int oneIdx = 0;
    
    for(int i = 0; i < input.size(); ++i){
        if(input[i] != '1') oneIdx++;
        else break; 
    }
    // oneIdx = 2
    tmp = startingProduction;
    for(int i = 0; i < oneIdx; ++i){// 0 1 
        for(int j = 0; j < startingProduction.size(); ++j){ // A1B
            if(startingProduction[j] == 'A'){ // tmp -> A1B
                tmp.insert(0,"0"); // tmp -> 00A1B
                printTransition(tmp);          
            }
        }
    }

    //find A and epsilon transition
    for(int k = 0; k < tmp.size(); ++k) // tmp -> 00A1B
        if(tmp[k] =='A') tmp.erase(k,1);

    // tmp -> 001B

    printTransition(tmp);
    
    for(int i = oneIdx + 1; i < input.size(); ++i){ // tmp -> 001B
        if(input[i] == '0'){
            int idx = tmp.size(); // 0010B
            tmp[idx - 1] = '0';
            tmp+='B';
            printTransition(tmp);
        }else{
            int idx = tmp.size(); // tmp -> 0010B
            tmp[idx - 1] = '1'; // tmp -> 00101B
            tmp += 'B';
            printTransition(tmp);
        }
    }

    // find B and epsilon transition
    for(int k = 0; k < tmp.size(); ++k){
        if(tmp[k] == 'B') tmp.erase(k,1); // tmp -> 00101B
    }

    printTransition(tmp);
    cout << endl;

    //Rightmost
    cout << "Rightmost: ";
    cout << "S => " << startingProduction;
    tmp = startingProduction; // tmp -> A1B
    // input: 00101
    // index: 01234
    for(int i = oneIdx+1; i < input.size(); ++i){ // starts from 3rd idx 
        if(input[i] =='0'){
            int idx = tmp.size();
            tmp[idx - 1] = '0';
            tmp+='B'; // A10B
            printTransition(tmp);
        }else{
            int idx = tmp.size();
            tmp[idx - 1] = '1';
            tmp+='B';//A101B
            printTransition(tmp);
        }
    }

    // epsilon transition
    for(int k = 0; k < tmp.size(); ++k){
        if(tmp[k] == 'B') tmp.erase(k,1);
    }

    printTransition(tmp);

    for(int i = 0; i < oneIdx; ++i){
        for(int j = 0; j < startingProduction.size(); ++j){
            if(startingProduction[j] == 'A'){
                tmp.insert(0,"0");
                printTransition(tmp);          
            }
        }
    }

    for(int k = 0; k < tmp.size(); ++k){
        if(tmp[k] == 'A') tmp.erase(k,1);
    }

    printTransition(tmp);
    cout << endl;
    return 0;
}

void printTransition(string &tmp){
    cout << " => " << tmp;
}