#include<stdio.h>

int main(){
    int  s[100],n,item;
    int flag=0;

    printf("Enter the number of elements");
    scanf("%d",&n);

    printf("Enter the elements");

    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }

    printf("Enter the number to be searched");
    scanf("%d",&item);

    for(int i=0;i<n;i++){
        if(s[i]==item){
            printf("Number is found at %d th position",i+1);
            flag=1;
        }
        
    }
    if (flag==0)
    {
         printf("Number cannot be found");
        
    }
    
           
            
        
       
return 0;
}