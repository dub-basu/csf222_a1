#include<stdio.h>

int abs(int n){
    if(n==0) return n;
    else if(n>0) return n;
    else return -n;
}

int main(){
    int n,neat=1,i,t;
    scanf("%d",&n);

    // them flags
    int multi_magnitude=0,negative1=0,positive1=0;


    for(i=0;i<n;i++){
        // collecting them flags XD
        scanf("%d",&t);

        if(t==-1) negative1++;
        else if(t==1) positive1++;
        else if(abs(t)>1)
            if(multi_magnitude==0) multi_magnitude++;
            else{ neat=0;}
    }

    if(negative1*multi_magnitude != 0) neat=0;
    if(negative1>1 && positive1==0) neat=0;

    if(neat==1) printf("%s\n","Yes");
    else printf("%s\n","No");
    
    return 0;
}
