#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swaplr(int order[],int swapl,int swapr){
    int k;
    for(k=swapr;k>swapl;k--){
        swap(&order[k],&order[k-1]);
    }
}

int main(){
    int n,flag=1;
    int k,j,i,FLAG=1;
    int FLAG2,flag2,swapl,swapr,FLAG3=0;
    scanf("%d",&n);
    int order[100];

    for(i=0;i<n;i++) order[i]=i;

    scanf("%d",&k);
    int first[100],second[100];
    for(i=0;i<k;i++){
        scanf("%d",&first[i]);
        scanf("%d",&second[i]);
    }

    FLAG=1;
    while(FLAG!=0){
        FLAG=0;

        for(i=0;i<k;i++,FLAG2=0){
            for(j=0,FLAG2=0;j<n;j++){
                if(first[i]==order[j] && FLAG2==0){ FLAG2=1; break;}
                else if(second[i]==order[j]){
                    FLAG=1;
                    FLAG2=1;
                    swapl=j;
                }
                else if(first[i]==order[j]){
                    swaplr(order,swapl,j);
                }
            }
        }
    }

    printf("%s","\n");
    for(i=0;i<n;i++) printf("%d ",order[i]);

    return 0;
}
