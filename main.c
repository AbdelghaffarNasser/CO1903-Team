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

//selectionSortAlgorithm
void SelectionSort_c2(char arr[], int SIZE){
    int i,j;
    char MIN;
    for(i = 0; i <= SIZE - 1; i++){
        MIN = i;
        for(j = i +1; j <= SIZE; j++)
            if(arr[j] < arr[MIN])
                MIN = j;
         char temp = arr[MIN];
         arr[MIN] = arr[i];
         arr[i] = temp;
    }
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
char binarySearch(char arr[], int first, int last, int middle, char search)
{
    while (first <= last)
      {

          if (arr[middle] < search)
          {
              first = middle + 1;
          }

          else if (arr[middle] == search)
          {
             printf("%c is present at index %d.\n", search, middle-1);
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
        printf("Please insert the size of your elements then insert the elements: \n");
        char arr[5000] = {0};
        int size;
        scanf("%d", &size);
        printf("Hey there, Enter your elements: \n");
        for(int i = 0; i <= size; i++){
            scanf("%c", &arr[i]);
        }
        /*printf("Original array: ");
        for(int j = 0; j <= size; j++){
            printf("%c", arr[j+1]);
        }*/
        printf("\nSorted array: ");

        SelectionSort_c2(arr, size);

        for(int k = 0; k <= size; k++){
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
    }else if(num == 3){
        printf("Please insert the size of your elements then insert the elements: \n");
        int size;
        scanf("%d", &size);
        char arr[size];

        printf("Enter your characters\integers: \n");
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
