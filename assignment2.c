#include <stdio.h>
int binarySearch(int arr[],int size,int element){
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
        
        
    }
    return -1;
    
}
int main(){
    int size;
    printf("Enter the size of an array:");
    scanf("%d",&size);
    printf("Enter array elements of size %d\n", size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int element;
    printf("Enter element that you want to search:");
    scanf("%d",&element);
    int indsearch=binarySearch(arr,size,element);
    if (indsearch !=-1)
    {
        printf("the element %d is found at index %d ",element,indsearch);
    }
    else
    {
        printf("element not found");
    }
    
    
    return 0;
}