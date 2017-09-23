#include<stdio.h>

void swap(int* a,int* b){
    int temp=*a;
    *a = *b;
    *b = temp;
}

int gcd(int p,int q){
    if(p>q) swap(&p,&q);
    int rem = q%p;
    if(rem==0) return(p);
    else return(gcd(rem,p));
}

int main(){
    // mode =1 if upwards; =-1 if downwards

    int p,q,s,k,rank=1,pi=1,qi=1,mode=-1;
    scanf("%d %d",&p,&q);

    if(p==0 || q==0){ printf("%s\n","Invalid number"); return 0;}
    while(!(pi==p && qi==q)){

        if(mode == 1){
            if(qi==1){
                mode*=-1;
                pi++;
            }
            else{
                pi++;
                qi--;
            }
        }
        else{
            if(pi==1){
                qi++;
                mode*=-1;
            }
            else{
                pi--;
                qi++;
            }
        }
        if(gcd(pi,qi)==1) rank++;
    }
    printf("rank = %d\n",rank);
    return 0;
}
