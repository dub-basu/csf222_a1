#include<stdio.h>

int factorial(int n){
    if(n==1 || n==0) return 1;
    else return(n*factorial(n-1));
}

int comb(int n,int r){
    int C = factorial(n)/(factorial(r)*factorial(n-r));
    return(C);
}

int result(int e,int m){
    int n=1,k,sum=0;
    while(e-n*m>=0){
        k=e-n*m;
        if(k == 0 || k == 1){
            sum++;
            n++;
        }
            
        else{
            sum+=comb(k-1,n-1);
            n++;
        }
    }
    
    return sum;
}

int main(){
    int e,m;
    scanf("%d %d",&e,&m);
    int r = result(e,m);
    printf("%d\n",r);
    return 0;
}
