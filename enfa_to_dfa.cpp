#include<bits/stdc++.h>
using namespace std;

int state_num,symbol_num,final_state_num;
vector<char> states,symbols,final_states;
vector<vector<vector<char>>> enfa_transition_table;
set<set<char>> dfa_states;
map<char,int> state_index,symbol_index;
vector<vector<int>> dfa_transition_table;
char starting_state;

void read_input();
void convert_to_dfa();
void get_eclosure(set<char> &eclose,set<char> st);
int get_index_of_set(set<char> st);
void print_dfa_states();
void print_dfa_transition_table();

int main(){
    freopen("enfa_to_dfa.txt","r",stdin);
    read_input();
    convert_to_dfa();
    print_dfa_states();
    print_dfa_transition_table();
    return 0;
}

void read_input(){
    cin>>state_num>>symbol_num;
    getchar();
    char ch;
    for(int i=0;i<state_num;i++){
        cin>>ch;
        states.push_back(ch);
        state_index[ch]=i;
    }
    getchar();
    for(int i=0;i<symbol_num;i++){
        cin>>ch;
        symbols.push_back(ch);
        symbol_index[ch]=i;
    }
    cin>>starting_state;
    cin>>final_state_num;
    for(int i=0;i<final_state_num;i++){
        cin>>ch;
        final_states.push_back(ch);
    }
    enfa_transition_table.resize(state_num,vector<vector<char>>(symbol_num,vector<char>(state_num)));
    int transition_num;
    for(int i=0;i<state_num;i++){
        for(int j=0;j<symbol_num;j++){
            cin>>transition_num;
            enfa_transition_table[i][j].clear();
            for(int k=0;k<transition_num;k++){
                cin>>ch;
                enfa_transition_table[i][j].push_back(ch);
            }
        }
    }
}

void get_eclosure(set<char> &eclose,set<char> st){
    for(auto s:st){
        eclose.insert(s);
        for(auto e:enfa_transition_table[state_index[s]][symbol_index['e']]){
            eclose.insert(e);
        }
    }
}

void convert_to_dfa(){
    set<char> temp;
    get_eclosure(temp,{starting_state});
    dfa_states.insert(temp);
    for(int i=0;i<dfa_states.size();i++){
        auto it=next(dfa_states.begin(),i);
        set<char> ds=*it;
        // if(is_used(ds)){
        //     continue;
        // }
        for(auto sym:symbols){
            set<char> st;
            for(auto s:ds){
                for(auto e:enfa_transition_table[state_index[s]][symbol_index[sym]]){
                    st.insert(e);
                }
            }
            temp.clear();
            get_eclosure(temp,st);
            dfa_states.insert(temp);
        }
        // used_states.insert(ds);
    }
    dfa_states.erase(dfa_states.begin());
    dfa_transition_table.resize(dfa_states.size(),vector<int>(symbol_num));
    for(auto ds:dfa_states){
        for(auto sym:symbols){
            set<char> st;
            for(auto s:ds){
                for(auto e:enfa_transition_table[state_index[s]][symbol_index[sym]]){
                    st.insert(e);
                }
            }
            temp.clear();
            get_eclosure(temp,st);
            dfa_transition_table[get_index_of_set(ds)][symbol_index[sym]]=get_index_of_set(temp);
        }
    }
}

int get_index_of_set(set<char> st){
    int i=0;
    for(auto s:dfa_states){
        if(s==st){
            return i;
        }
        i++;
    }
    return -1;
}

void print_dfa_states(){
    int i=0;
    cout<<endl;
    cout<<"States for the DFA:"<<endl;
    for(auto s:dfa_states){
        cout<<i++<<"={";
        for(auto e:s){
            cout<<" "<<e;
        }
        cout<<" }"<<endl;
    }
    cout<<endl;
}

void print_dfa_transition_table(){
    cout<<"Transition table for the DFA:"<<endl;
    cout<<"\t";
    for(auto sym:symbols){
        if(sym=='e'){
            continue;
        }
        cout<<"Sym-"<<sym<<"\t";
    }
    cout<<endl;
    int i=0;
    for(auto s:dfa_states){
        cout<<"State-"<<i++<<"\t";
        for(auto sym:symbols){
            if(sym=='e'){
                continue;
            }
            cout<<dfa_transition_table[get_index_of_set(s)][symbol_index[sym]]<<"\t";
        }
        cout<<endl;
    }
}