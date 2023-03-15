//01
//01
//01
#include<stdio.h>

struct student{

    int id;
    char name[25];
    int marks[5];
    int total;
};

int main(){

    int n,i,j;
    char dummy;
    scanf("%d",&n);

    struct student a[1000];

    for(i=0;i<n;i++){

        scanf("%d",&a[i].id);

        scanf("%c",&dummy);

        scanf("%[^\n]",a[i].name);//[^\n] means we can input blankspaces too, input ends with finding newline as an input
 
        a[i].total = 0;

        for(j=0 ; j<5 ; j++){
            scanf("%d",&a[i].marks[j]);

            a[i].total = a[i].total + a[i].marks[j];

        }

    }

    for(i=0;i<n-1;i++){
        for(j=i+1; j<n ; j++){

            if(a[i].total < a[j].total){
                struct student temp;

                temp = a[i];

                a[i] = a[j];

                a[j] = temp;

            }

        }
    }



    for(i=0;i<n;i++){

        printf("%5d%5d %-20s%5d%5d%5d%5d%5d%5d\n",i+1,a[i].id,a[i].name,a[i].total,a[i].marks[0],a[i].marks[1],a[i].marks[2],a[i].marks[3],a[i].marks[4]);

    }

    return 0;
}