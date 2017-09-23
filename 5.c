#include<stdio.h>

int existence(int x[],int y[],int X,int Y,int size){
    int i;
    for(i=0;i<=size;i++)
        if(x[i]==X && y[i]==Y) return 1;
    return 0;
}

int main(){
    int n,k,x[100],y[100],c=0,i,j,C;
    scanf("%d",&n);
    scanf("%d",&k);

    int matrix[100][100];
    for(i=0;i<n+1;i++)
        for(j=0;j<n+1;j++)
            matrix[i][j]=0;

    for(i=0;i<k;i++,c++){ scanf("%d %d",&x[i],&y[i]); matrix[x[i]][y[i]]=1;}

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
    }

    c--;
    do{
        C=c;
        for(i=0;i<c;i++){
            for(j=i+1;j<=c;j++){
                // printf("%d %d %d %d %d %d\n",i,j,x[i],y[i],x[j],y[j]);
                if(x[i]==y[j] && existence(x,y,x[j],y[i],c)==0){
                    c++;
                    matrix[x[j]][y[i]]=1;
                    x[c]=x[j];
                    y[c]=y[i];
                }
                else if(y[i]==x[j] && existence(x,y,x[i],y[j],c)==0){
                    c++;
                    matrix[x[i]][y[j]]=1;
                    x[c]=x[i];
                    y[c]=y[j];
                }
            }
        }
    }while(C!=c);

    int none=0;
    for(i=0;i<n;i++,none=0){
        printf("\n");
        for(j=0;j<n;j++)
            if(matrix[i][j]==1){
                if(i!=j) printf("%d ",j );
                none=1;
            }
        if(none==0) printf("-");
    }

    // printf("\n\n");
    // for(i=0;i<c;i++) printf("%d %d %d \n",i,x[i],y[i]);
    //
    // printf("\n\n");
    // for(i=0;i<n;i++){
    //     printf("\n");
    //     for(j=0;j<n;j++)
    //         printf("%d ",matrix[i][j]);
    // }
    return 0;

}
