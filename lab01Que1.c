#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MAX 100

char str[5][MAX];

int generateLen(){
    int num = rand()%(MAX+1);
    // printf("len: %d\n",num);
    return num;
}

int calculateLength(int i){
    int count=0,j=0;
    while(str[i][j]!='\0'){
        count++;
        j++;
    }
    // printf("%s",s[i][j]);
    return count;
    
}

void generateString( int idx ){
    
    int n = generateLen();
     
     for(int i=0; i<n; ++i){
        str[idx][i] ='0'+rand()%2;//integer char e convert hoy
     }
    
}

bool check(char* w){
    int i=0;
    bool b1=true;
    while(w[i]!='\0'){
        if(w[i]!='0' && w[i]!='1'){
             b1=false;
        }
        i++;
    }
    return b1;
}

int main(){

int n;

    for(int i=0; i<5; i++){
        
       generateString(i);
    }

     for(int i=0;i<5;i++){
        printf("%s \n",str[i]);
    }

    for(int i=0;i<5;i++){
        int length=calculateLength(i);
        printf("length of string %d is %d\n",i+1,length);
    }

    char w[100];
    printf("Enter a string named w:");
    scanf("%s",&w);

    bool b=check(w);
    if(b){
        printf("W is from the alphabet\n");

    }
    else{
        printf("W is not from the alphabet\n");
    }

    char x[100];
    char y[100];


    printf("Enter a string named x:");
    scanf("%s",&x);
    printf("Enter a string named y:");
    scanf("%s",&y);

    // printf("string x-%s\n",x);
    // printf("string y-%s\n",y);

    char z[100];

    int i=0,j=0;

    while(x[i]!='\0'){
        z[j]=x[i];
        j++;
        i++;
    }
    i=0;
    while(y[i]!='\0'){
        z[j]=y[i];
        j++;
        i++;
    }
    z[j]='\0';

    printf("Concatenated string z= %s\n", z);

    return 0;
}