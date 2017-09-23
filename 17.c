#include<stdio.h>

void arr_input(int a[],int n){
    int i;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
}

int existence(int a[],int size,int n){
    int i;
    for(i=0;i<size;i++) if(a[i]==n) return 1;
    else return 0;
}

void arr_print(int an[],int set[],int l){
    int i;
    for(i=0;i<l;i++)
        if(set[i]==1) printf("%d ",an[i]);
}

void getlist(int an[],int set[],int l,int depth){
    int i,flag=0;
    for(i=depth;i<l;i++){
        if(set[i]==2){
            flag=1;
            set[i]=0;
            getlist(an,set,l,i+1);
            set[i]=1;
            getlist(an,set,l,i+1);
        }
    }
    if(flag==0){
        arr_print(an,set,l);
    }
}

int main(){
    int n,k,l,an[100],ak[100],al[100],i;
    arr_input(an,scanf("%d",&n));       // total skills
    int matrix[3][100];                 // n
    arr_input(ak,scanf("%d",&k));       // colossus' skills
    arr_input(al,scanf("%d",&l));       // skills required in partner

    // populate matrix
    for(i=0;i<n;i++){
        if(existence(ak,k,an[i])==1) matrix[0][i]=1; else matrix[0][i]=0;
        if(existence(al,l,an[i])==1) matrix[1][i]=1; else matrix[1][i]=0;

        if(matrix[0][i]==1)
            if(matrix[1][i]==0) matrix[2][i]=1;
            else matrix[2][i]=2;
        else matrix[2][i]=0;
    }

    getlist(an,matrix[2],l,0);

    return 0;
}
