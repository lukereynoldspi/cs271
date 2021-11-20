#include <stdio.h>

/* Ex.1: Return the larger value */
int max(int x, int y) 
{
   if (x > y)
   {
	   return x;
   }
   
   if (y > x)
   {
	   return y;
   }
   
   else
	   return x;
   
}

/* Ex.2: Add [0..100] and return the sum */
int add100()
{
   int i = 0;
   int num_sum = 0;
   while(i <= 100)
   {
	   num_sum = num_sum + i;
	   i++;
   }
   
   return num_sum;
}  

/* Ex.3: Sum the elements in the array */
int sum(int arr[], int n)
{
   int final_sum = 0;
   
	for (int i = 0; i < n; i++)
	   final_sum += arr[i];

	return final_sum;
}  

/* Ex.4: Find the largest element in the array */
int largest(int arr[], int n)
{
   int largest_num = 0;
   
	for (int i = 0; i < n; i++)
		if (arr[i] > largest_num)
			largest_num = arr[i];
		
	return largest_num;   
	   
	
}
int main() {
    // Exercise 1
    printf("Sum of 1..100 is %d\n", add100());        
    
    // Exercise 2
    printf("The max of 12 and 20 is %d\n", max(12, 20));
    printf("The max of 37 and 14 is %d\n", max(37, 14));

    // Create an array and calculate its length n
    int arr[] = {12, 5, 7, 14, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exercise 3
    printf("Sum of the array is %d\n", sum(arr, n));

    // Exercise 4
    printf("Largest element in the array is %d\n", largest(arr, n));
   // main returns 0 if exiting without error
   return 0;
}