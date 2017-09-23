#include<stdio.h>

int existence(int x[],int y[],int X,int Y,int c){
    int i;
    for(i=0;i<c;i++) if(x[i]==X && y[i]==Y) return 1;
    return 0;
}

int is_por(int x[],int y[],int c){
    int por=0;
    int i,j,rflag=0;
    for(i=0;i<c;i++){
        rflag=0;
        for(j=0;j<c;j++){
            if(i==j) break;
            
            // can be optimized for lesser operations (but lesser readability as well :P)

            if(x[i]==y[j] && x[j]==y[i]) return 0;//symmetric check
            if(x[i]==x[j] && x[i]==y[j]) rflag=1;// reflexive check

            //check for transivity...
            if(x[i]==y[j] && existence(x,y,x[j],y[i],c)==0){
                return 0;
            }
            else if(y[i]==x[j] && existence(x,y,x[i],y[j],c)==0){
                return 0;
            }
            // ...transivity check over

        }
        if(x[i]==y[i]) rflag=1;
        if(rflag==0) return 0;
    }
    return 1;
}

int main(){
    int n,k,x[100],y[100],c=0,i,j;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<k;i++) scanf("%d %d",&x[i],&y[i]);


    // c=i-1;
    // for(i=0;i<=c;i++){
    //     printf("a %d\n a",c );
    //     for(j=i+1;j<c;j++){
    //         if(x[i]==y[j] && existence(x,y,x[j],y[i],c)==0){
    //             c++;
    //             x[c]=x[j];
    //             y[c]=y[i];
    //         }
    //         else if(y[i]==x[j] && existence(x,y,x[i],y[j],c)==0){
    //             c++;
    //             x[c]=x[i];
    //             y[c]=y[j];
    //         }
    //     }
    // }

    if(is_por(x,y,k)==0)
        printf("%s\n","No");
    else
        printf("%s\n","Yes");
    // int flag,test;
    // for(i=0;i<=c;i++){
    //     flag=0;
    //     for(j=i+1;j<=c;j++){
    //         if(x[i]==y[i] || (x[i]==x[j] && x[i]==y[j])){flag = 1; break;}
    //     }
    //     if(flag==0){printf("%s\n","Not reflexive"); return 0;}
    // }
    // printf("%s\n","Reflexive");
    return 0;
}
