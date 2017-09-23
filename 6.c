#include<stdio.h>

void mat_print(int matrix[][100],int n){
    int i,j;
    printf("\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
    }
}

int row_check(int matrix[][100],int n,int a){
    // returns 0 if row empty, 1 otherwise
    int i;
    for(i=0;i<n;i++) if(matrix[a][i]!=0) return 1;
    return 0;
}

int col_check(int matrix[][100],int n,int a){
    // returns 0 if col empty, 1 otherwise
    int i;
    for(i=0;i<n;i++) if(matrix[i][a]!=0) return 1;
    return 0;
}

int main(){
    int n,k,j,i,m,o,t;
    int order[100];
    int truths[100],ntruths=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int matrix[100][100];
    for(i=0;i<n;i++) for(j=0;j<n;j++) matrix[i][j]=0;

    for(i=0;i<k;i++){
        scanf("%d ",&m);
        for(j=0;j<m+1;j++) scanf("%d",&order[j]);
        for(j=0;j<m;j++) matrix[order[j]][order[m]]=1;
        // mat_print(matrix,n);
    }

    scanf("%d",&o);
    for(i=0;i<o;i++){
        scanf("%d",&t);
        truths[ntruths++]=t;
        for(j=0;j<n;j++){
            matrix[t][j]=0;
        }
    }
    // printf("%s\n","ggwp");

    // mat_print(matrix,n);

    int N=ntruths;
    int changes;
    do{
        // printf("%d\n",changes );
        changes=0;
        for(i=0;i<n;i++)
            if(col_check(matrix,n,i)==0){
                for(j=0;j<n;j++) if(matrix[i][j]!=0){ matrix[i][j]=0; changes++;}
            }
    }while(changes!=0);

    // mat_print(matrix,n);
    for(i=0;i<n;i++) if(row_check(matrix,n,i)==0) printf("%d ",i);

    return 0;
}
