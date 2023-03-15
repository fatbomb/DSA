#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c,d;
    scanf("%d.%d",&a,&b);
    scanf("%d.%d",&c,&d);
    int ans=a+c;
    int flo=b+d;
    ans+=(flo/1000000);
    flo=(flo%1000000);
    int t=log10(flo);
    printf("%d",ans);
    if(flo>0){
        while(flo%10==0){
            flo/=10;
        }
        printf(".");
        for(int i=0;i<6-t-1;i++){
            printf("0");
        }
        printf("%d\n",flo);
    }


    return 0;



}