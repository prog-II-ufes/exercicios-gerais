#include <stdio.h>

int decim (int n) {

    int i = 1,a;
    int octal = 0;

    if(n<=7){
        octal=n;
    }else{

        while(n>=8){
            a=n%8;
            n=n/8;
            octal = octal + a * i;
            i *= 10;
        }
        n=n%8;
        octal = octal + n * i;
    }

    return octal;
}

int main()  
{
    int n,octal;  

    scanf("%d",&n);  

    octal=decim(n);  

    printf("%d\n",octal);    



    return 0;    
}