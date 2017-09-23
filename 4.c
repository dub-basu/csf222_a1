#include<stdio.h>

int notin(int path[],int d,int k){
    int i;
    for(i=0;i<d;i++) if(path[i]==k) return 1;
    return 0;
}

void arr_print(int arr[],int n){
    int i;
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void depth(int matrix[][100],int start,int d,int n,int path[]){
    int i,j,flag=0,count;
    // printf("depth: %d \n",d); arr_print(path,d);
    // arr_print(path,d);
    // printf("depth : %d \n",d);
    // printf("start %d \n",start);
    if(d>=n){
        // printf("%s","ggwp");
        for(i=0,count=0;i<n;i++,count=0){
            for(j=0;j<n;j++) if(i==path[j]) count++;
            if(count!=1) flag=1;
        }
        if(flag==0) arr_print(path,n);
    }
    else
        for(i=0;i<n;i++)
            if(matrix[start][i]==1 && notin(path,d,i)==0){
                path[d] = i;
                arr_print(path,d+1);
                d++;
                depth(matrix,i,d,n,path);
            }
}

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
            if(i==j) matrix[i][j] = 0;
            else matrix[i][j]=1;

    for(i=0;i<k;i++,c++){ scanf("%d %d",&x[i],&y[i]); matrix[y[i]][x[i]]=0;}

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

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
    }

    int flag=0;
    int path[10];
    for(i=0;i<n;i++,flag=0){
        for(j=0;j<n;j++) if(matrix[j][i]==1){ flag=1; break;}
        if(flag==0){
            path[0] = i;
            depth(matrix,i,1,n,path);
        }
    }
    return 0;
}
