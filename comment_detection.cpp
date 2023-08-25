#include<bits/stdc++.h>
using namespace std;

string s;

int main(){

    // ifstream in;
    // in.open("testcode.c");

    FILE *fp=fopen("testcode.c", "r");


    int i=0,num_line=1;

    while(!feof(fp)){
        char ch;
        ch=fgetc(fp);
        if(ch>=0 && ch<=127){
            s+=ch;
        }
    }
    // cout<<s<<endl;

    for(;i<s.size();i++){

        if(s[i]=='\n') num_line++;

        if((s[i]=='/' && s[i+1]=='/')){
            cout<<"Single line comment detected at line number:"<<num_line<<endl;
            int j=i+2;
            cout<<"The comment is:";
            while(1){
                printf("%c",s[j]);
                j++;
                if(s[j]=='\n'){
                    break;
                }
            }
            cout<<endl;
        }

        if((s[i]=='/' && s[i+1]=='*')){
            int flag=0;
            cout<<"Multi-line comment detected at line number:"<<num_line<<endl;
            int j=i+2;
            cout<<"The comment is:";
            while(1){
                printf("%c",s[j]);
                j++;
                if(s[j]=='*' && s[j+1]=='/'){
                    break;
                }

                if(s[j]=='\n'){
                    flag=1;
                    break;
                }
            }

            if(flag)cout<<"incomplete comment"<<endl;
            if(flag==0) cout<<endl;

        }
        
    }

}