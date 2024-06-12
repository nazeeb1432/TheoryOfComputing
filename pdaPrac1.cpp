#include<bits/stdc++.h>
using namespace std;

#define z 'z'
int num_states,num_alphabets;
vector<char> states,alphabets,stack_alphabets;
char start_state,final_state,current_state;
char x;
stack<char> s;
string input;

int main(){

    freopen("pdaPrac1.txt", "r", stdin);

    cin>>num_states>>num_alphabets;
    getchar();

    cout<<num_states<<" "<<num_alphabets<<endl;

    for(int i=0;i<num_states;i++)
    {
        cin>>x;
        states.push_back(x);
    }

    for(int i=0;i<num_states;i++){
        cout<<states[i]<<" ";
    }
    cout<<endl;

    getchar();
    stack_alphabets.push_back(z);

    for(int i=0;i<num_alphabets;i++){
        cin>>x;
        alphabets.push_back(x);
        stack_alphabets.push_back(x);
    }
    getchar();

    stack_alphabets.pop_back();//1 is not part of the stack_alphabet

    for(int i=0;i<num_alphabets;i++){
        cout<<alphabets[i]<<" ";
    }
    cout<<endl;

    cin>>start_state>>final_state;
    getchar();

    s.push(z);

    cout<<start_state<<" "<<final_state<<endl;

    cin>>input;

    cout<<"Input: "<<input<<endl;

    


    






}




