#include <stdio.h>
#include <stdlib.h>

// Merge the two half into a sorted data

//mergeFunctionAlgorithm
void merge(char arr[], int left, int middle, int right)
{
    int i, j, k;
    int len1 = middle - left + 1;
    int len2 =  right - middle;

    // Create temp arrays
    char L[len1], R[len2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < len1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < len2; j++)
        R[j] = arr[middle + 1 + j];

     // Merge the temp arrays back into arr[l..r]

     i = 0; // Initial index of first sub array
     j = 0; // Initial index of second sub array
     k = left; // Initial index of merged sub array or it can be 0 also

     while (i < len1 && j < len2)
     {
         if (L[i] <= R[j])
         {
             arr[k] = L[i];
             i++;
         }
         else
         {
             arr[k] = R[j];
             j++;
         }
         k++;
     }

     // Copy the remaining elements of L[], if there are any
     while (i < len1)
     {
         arr[k] = L[i];
         i++;
         k++;
     }

     // Copy the remaining elements of R[], if there are any
     while (j < len2)
     {
         arr[k] = R[j];
         j++;
         k++;
     }
 }

// l is for left index and r is right index of the
// sub-array of arr to be sorted

//mergeSortAlgorithm
void mergeSort(char arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int middle = left + (right - left)/2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
     }
 }

//SelectionSortAlgorithm
void swap_n(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_c(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void MIN_n(int i, int arr[], int SIZE){
    int MIN;
    for(int j = i +1; j < SIZE; j++){
        MIN = i;
        if(arr[j] < arr[MIN]){
            MIN = j;
            swap_n(&arr[MIN], &arr[i]);
        }
    }
}

void MIN_c(int i, char arr[], int SIZE){
    int MIN;
    for(int j = i +1; j < SIZE; j++){
            MIN = i;
            if(arr[j] < arr[MIN]){
                MIN = j;
                swap_c(&arr[MIN], &arr[i]);
        }
    }
}
void SelectionSort_n(int arr[], int SIZE){
    for(int i = 0; i < SIZE - 1; i++){
        MIN_n(i,arr,SIZE);
    }
}
void SelectionSort_c(char arr[], int SIZE){
    for(int i = 0; i < SIZE - 1; i++){
            MIN_c(i,arr,SIZE);
    }
}
void PrintArray_n(int arr[], int SIZE){
    int i;
    for(i = 0; i < SIZE; i++)
        printf("%d  ", arr[i]);
}
void PrintArray_c(char arr[], int SIZE){
    int i;
    for(i = 0; i < SIZE; i++)
        printf("%c  ", arr[i]);
}

//bubbleSortAlgorithm
void bubblesort (char *arr,int x){
    int i, j;
    for (i = 0; i <= x-1; i++){
        for (j = 0; j <= x-i-1; j++){
            if (arr[j] > arr[j+1]){
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

//binarySearchAlgorithm
void binarySearch(char arr[], int first, int last, int middle, char search)
{
    while (first <= last)
      {

          if (arr[middle] < search)
          {
              first = middle + 1;
          }

          else if (arr[middle] == search)
          {
             printf("%c is present at index %d.\n", search, middle);
             break;
          }
          else
             last = middle - 1;

          middle = (first + last)/2;
       }
       if (first > last)
        {
                printf("Not found %c is not present in the list.\n", search);
        }
}
void binarySearchi(int arr[], int first, int last, int middle, int search)
{
    while (first <= last)
      {

          if (arr[middle] < search)
          {
              first = middle + 1;
          }

          else if (arr[middle] == search)
          {
             printf("%d is present at index %d.\n", search, middle);
             break;
          }
          else
             last = middle - 1;

          middle = (first + last)/2;
       }
       if (first > last)
        {
                printf("Not found %c is not present in the list.\n", search);
        }
      return 0;
}


int main()
{
    printf("##### Enter the number of the sort that you want to use #####\n");
    printf("Press 1 for Merge Sort\nPress 2 for Selection Sort\nPress 3 for Bubble Sort\n");
    int num;
    scanf("%d", &num);
    if(num == 1){
        printf("Please insert the size of your elements then insert the elements (just independent single integers: 0-9): \n");
        char arr[5000] = {0};
        int left, right, size;
        scanf("%d", &size);
        right = size;
        left = 0;
        printf("Hey there, Enter your elements: \n");
        for(int i = left; i <= right; i++){
            scanf("%c", &arr[i]);
        }

        /*printf("Original array: ");
        for(int j = left; j <= right; j++){
            printf("%c", arr[j+1]);
        }*/
        printf("\nSorted array: ");

        mergeSort(arr, left, right);

        for(int k = left; k <= right; k++){
            printf("%c", arr[k+1]);
        }

        int first = 0;
        int last = size;
        int middle = (first+last)/2;
        char search;
        printf("\nEnter the Number to find:\n");
        scanf("%s", &search);
        binarySearch(arr,first, last, middle, search);

        printf("\nDone :D ");

    }else if(num == 2){
        int c,s;
        printf("Please insert your choice:\n\n");
        printf("1-Sort integers\t 2-Sort characters\n");
        scanf("%d",&c);
        printf("Please insert the size of your array: ");
        scanf("%d",&s);
        if(c==1){
            int arri[s];
            printf("\nInsert your elements one per line:\n");
            for(int i = 0; i < s; i++)
                scanf("%d",&arri[i]);
            SelectionSort_n(arri, s);
            printf("\n\nAfter the array of integers is sorted\n\n");
            PrintArray_n(arri, s);
            int first = 0;
            int last = s;
            int middle = (first+last)/2;
            int search;
            printf("\n\nEnter the Number to find: ");
            scanf("%d", &search);
            binarySearchi(arri,first, last, middle, search);
            }
        else{
            char arrc[s];
            printf("\nInsert your elements one per line:\n");
            for(int i = 0; i < s; i++)
                scanf("%s",&arrc[i]);
            SelectionSort_c(arrc, s);
            printf("\n\nAfter the array of characters is sorted:\n\n");
            PrintArray_c(arrc, s);
            int first = 0;
            int last = s;
            int middle = (first+last)/2;
            char search;
            printf("\n\nEnter the Character to find: ");
            scanf("%s", &search);
            binarySearch(arrc,first, last, middle, search);

            }

    }

    else if(num == 3){
        printf("Please insert the size of your elements then insert the elements: \n");
        int size;
        scanf("%d", &size);
        char arr[size];

        printf("Enter your integers/characters one per line: \n");
        for(int i = 0; i < size; i++){
            scanf("%s", arr+i);
        }

        printf("\nSorted array: ");

        bubblesort(arr, size);

        for(int k = 0; k < size; k++){
            printf("%c", arr[k+1]);
        }

        int first = 0;
        int last = size;
        int middle = (first+last)/2;
        char search;
        printf("\nEnter the Number to find:\n");
        scanf("%s", &search);
        binarySearch(arr,first, last, middle, search);


    }
}
