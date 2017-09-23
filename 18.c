#include<stdio.h>

void arr_print(int arr[],int n){
    int i;
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void search(int gadgets[],int x,int size,int belt[],int depth,int capacity){
    int i;
    if(x>size) return;
    else if(depth==capacity){
        // printf("x = %d\n",x);
        arr_print(belt,capacity);
    }
    else{
        int count = depth-1;
        for(i=x;count<=capacity;i++,count++){
            belt[depth]=gadgets[i];
            search(gadgets,i+1,size,belt,depth+1,capacity);
        }
    }
}

int main(){
    int n,k;
    scanf("%d",&n);
    int i,gadgets[100],belt[100],depth=0;
    for(i=0;i<n;i++) scanf("%d",&gadgets[i]);
    scanf("%d",&k);
    for(i=0;i<=n-k;i++){
        belt[0]=gadgets[i];
        depth=1;
        // printf("i : %d\n",i);
        search(gadgets,i+1,n,belt,depth,k);
    }
    // arr_print(gadgets,n);
    return 0;
}
