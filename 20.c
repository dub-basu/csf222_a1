#include<stdio.h>

int pow_units(int n,int p,int ori){
    if(p==0) return(1);
    n%=10;

    if(p==1) return(n%10);
    else return pow_units(n*ori,--p,ori);
}

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    printf("%d\n",pow_units(n,p,n));
    return(0);
}
