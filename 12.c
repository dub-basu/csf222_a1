    #include<stdio.h>
#include<math.h>

int isprime(int n){
    int i;
    for(i=2;i<n;i++) if(n%i==0) return 0;
    return 1;
}

void list_print(int a[],int n){
    int i;printf("\n");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

int get_primes(int primes[],int n){
    int i,count=0;
    for(i=2;i<n;i++){
        if(isprime(i)==1){
            primes[count++] = i;
            // printf("%d\n",primes[count] );
        }
    }
    return count;
}

void change_matrix(int matrix[][100],int a,int b,int factors[],int no_of_factors){
    int i,j,row_index=0,col_index=0;
    for(i=0;i<no_of_factors;i++){
        if(a==factors[i]) row_index = i;
        if(b==factors[i]) col_index = i;
    }
    // printf("%s\n", "as");
    matrix[row_index][col_index] = 1;
}

int relations_count(int n,int primes[],int no_of_primes,int sum,int matrix[][100],int factors[],int no_of_factors){
    int i=0, temp;
    int row_index,col_index,j;
    if(n==1) return sum;

    for(i=0;i<no_of_primes;i++){
        if(primes[i]>n) break;
        // printf("%d\n",primes[i]);
        if(n%primes[i]==0){
            for(j=0;j<no_of_factors;j++){
                if(n==factors[j]) row_index = j;
                if(n/primes[i]==factors[j]) col_index = j;
            }
            // printf("%s\n", "as");
            matrix[row_index][col_index] = 1;
            change_matrix(matrix,n,n/primes[i],factors,no_of_factors);
            // printf("prim : %d %d %d %d\n",n,primes[i],n/primes[i],sum);
            sum++;
            sum+=relations_count(n/primes[i],primes,no_of_primes,sum,matrix,factors,no_of_factors);
        }
    }
    return sum;
}

int all_factors(int n,int factors[]){
    int i;
    int count=0;
    int rootn;
    rootn = sqrt(n);
    for(i=1;i<=rootn;i++){
        if(n%i==0){
            factors[count++] = i;
            factors[count++] = n/i;
        }
    }
    if(rootn*rootn==n) count--;
    return count;
}

int main(){
    int n,i,sum=1,no_of_factors,j,result=0;
    scanf("%d",&n);
    int primes[100],no_of_primes=0;int matrix[100][100];
    int factors[100];
    no_of_primes = get_primes(primes,n);
    list_print(primes,no_of_primes);

    no_of_factors = all_factors(n,factors);

    for(i=0;i<no_of_factors;i++) for(j=0;j<no_of_factors;j++) matrix[i][j];


    sum = relations_count(n,primes,no_of_primes,sum,matrix,factors,no_of_factors);
    for(i=0;i<no_of_factors;i++,printf("\n")) for(j=0;j<no_of_factors;j++) if(matrix[i][j]==1) result++;
    printf("%d\n",result);
    return 0;
}
