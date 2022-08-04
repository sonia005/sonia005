#include<stdio.h>
int main()
{
    int arr[]={5,10,15,20,25,30};
    int max=arr[0];
    int i, j=6, loc=1;
    printf("Given array is: \n");
    for(i=0;i<j;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for (i=0;i<j;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            loc=i;
        }
    }
    printf("\n\nMax value is: %d\n\nLocation of the Max value: %d\n\n",max,loc);
    return 0;
}
