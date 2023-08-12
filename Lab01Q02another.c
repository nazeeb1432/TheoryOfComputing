#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void Binary(int n,char A[]){
    if(n<1){
        printf("%s\n",A);
    }
    else{
        A[n-1]='a';
        Binary(n-1,A);
        A[n-1]='b';
        Binary(n-1,A);
    }
}

int isPalindrome(char str[]){
    int left=0;
    int right=strlen(str)-1;

    while(left<right){
        if(str[left]!=str[right]){
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

int main(){

    int k;
    printf("Enter the value of k:");
    scanf("%d", &k);
    printf("\nΣ^%d:\n", k);

    char A[k+1];
    A[k]='\0';

    Binary(k,A);

    char w[100];
    printf("Enter a string w to check if it is a palindrome:");
    scanf("%s",w);

    if(isPalindrome(w)){
        printf("\nw is a palindrome\n");
    }
    else{
        printf("\nw is not a palindrome\n");
    }


    return 0;
}