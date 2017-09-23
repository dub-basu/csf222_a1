#include<stdio.h>

int compare(int ones,int zeros){
    if(ones==zeros) return 1;
    else return 0;
}

int result(int n,int ones,int zeros){

    if(n==0) return compare(ones,++zeros);
    else if(n==1) return compare(++ones,zeros);

    int rem = n%2;
    if(rem==1) ones++;
    else zeros++;
    n/=2;

    return result(n,ones,zeros);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%s\n",result(n,0,0)?"Yes":"No");
    return 0;
}
