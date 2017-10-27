// Skeleton code for  ECE2036 insertion sort assignment
// Benjamin Klein, Georgia Tech, Spring 2017
//  based on code written by George Riley


// Student Name:  John Blasco

#include <iostream>

using namespace std;


//  Here's where we'll put the functions your code will use

//  This is the sorting function, which you will write
void InsertionSort(int data[], int size)
{ 
  cout << "Sorting array... " << endl;

  // Sort the array "data" of length "size" using insertion sort algorithm
  // WRITE YOUR CODE HERE
  int tempVal;
  for (int i = 0; i < size; i++)
  {
    tempVal = data[i];
    int j = i - 1;
    while ( j >= 0 && data[j] > tempVal)
    {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = tempVal;
  
  }



}  // end function


//  Function to check whether array is sorted correctly
int CheckIt(int data[], int size)
{
  int errorCount = 0;
  for (int i = 0; i < size-1; ++i)
    {
      if (data[i] > data[i + 1])
        { //    Oops, not sorted properly 
          errorCount++;
        }
    }
  return errorCount;
}  // end function


//  Function to print array
void printArray(int data[], int size)
{
  cout << "The array contains the following: " << endl;
  for  (int i = 0; i < size; i++)
    cout << data[i] << ", ";
  cout << endl;
}  // end function 



//  main function
int main()
{
  // Seed the random number generator with the current time 
  srand(static_cast<unsigned int>(time(0)));

//  We'll start by making a small array of random numbers and sorting it
  int size = 10;
  // smallArray is the array to sort
  int smallArray[size];
  // Fill the array 'data' with random numbers 
  for (int i = 0; i < size; ++i)
  {
     smallArray[i] = rand() % 100;
  }

  // Let's look at the array contents
  printArray(smallArray, size);

  // Now call the insertion sort function
  InsertionSort(smallArray, size);

  //  Let's look at the array again
  printArray(smallArray, size);
  
  //  Call automated array sorting checker to ensure it's sorted correctly 
  int errorCount = CheckIt(smallArray, size);
      
  if (errorCount == 0)
  {
      cout << "Congrats!  Array sorted correctly, size =  " << size << endl;
  }
  else
  {
     cout <<"Oops, " << errorCount << " errors found " << endl;
  }



//  Now let's try making a much larger array of random numbers and sorting it
  size = 10000;
  // bigArray is the array to sort
  int bigArray[size];
  // Fill the array 'bigArray' with random numbers 
  for (int i = 0; i < size; ++i)
  {
     bigArray[i] = rand() % 100;
  }

  // Now call the insertion sort function
  InsertionSort(bigArray, size);

  //  Call automated array sorting checker to ensure it's sorted correctly 
  errorCount = CheckIt(bigArray, size);
      
  if (errorCount == 0)
  {
      cout << "Congrats!  Array sorted correctly, size =  " << size << endl;
  }
  else
  {
     cout <<"Oops, " << errorCount << " errors found " << endl;
  }
}

