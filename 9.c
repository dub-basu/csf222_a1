#include<stdio.h>

int power_2(int k,int current_power){
    if(k%2==0) return(power_2(k/2,current_power+1));
    else return current_power;
}

int main(){
    int n,i,uatu_wins=1,total_powers_of_2=0;
    scanf("%d",&n);
    int dim[100];
    for(i=0;i<n;i++) scanf("%d",&dim[i]);

    //checks how many powers of 2 are contained in the leftover dimensions
    for(i=0;i<n;i++) total_powers_of_2+=power_2(dim[i],0);

    if(total_powers_of_2==0 || total_powers_of_2%2==0) uatu_wins=0;

    if(uatu_wins==1) printf("%s\n","Uatu");
    else printf("%s\n","Galactus");
    return 0;
}
