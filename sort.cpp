#include <iostream>
using namespace std;
void swap(int* list, int one, int two) {
	int temp = list[one];
	list[one] = list[two];
	list[two] = temp;
}

int findPivot(int head, int tail) {
	return (head+tail)/2;
}

void insertSort(int* list, int n) {
  for(int i=1;i<n;i++) {
    //to insert `i`th element in its right place
    for(int j=i;j>0;j--) {
      if(list[j]<list[j-1])
        swap(list, j, j-1);
    }
  }
}

void bubbleSort(int* list, int n) {
  for(int i=0;i<n;i++)
    for(int j=n-1;j>i;j--)
      if(list[j]<list[j-1])
        swap(list, j, j-1);
}

void selectSort(int* list, int n) {
  int minIndex;
  for(int i=0;i<n;i++) {
    minIndex = i;
    // find the min value in the `i`th right part of the array
    for(int j=i;j<n;j++) {
      if(list[minIndex]>list[j])
        minIndex = j;
    }
    // get the min value in right place
    swap(list, i, minIndex);
  }
}

//insert sort with incresment `incr`
void insertSort2(int* list, int n, int from, int incr) {
  for(int i=from+incr;i<n;i+=incr)
    for(int j=i;j>from;j-=incr)
      if(list[j]<list[j-incr])
        swap(list, j, j-incr);
}
void shellSort(int* list, int n) {
  for (int i = n/2; i > 0; i/=2)
  {
    for (int j = 0; j < i; ++j)
    {
      insertSort2(list, n, j, i);
    }
  }
}

//partition for quick sort
int partition(int* list, int head, int tail, int pivot) {
	do {  
    while (list[head] < pivot) head++;
    while ((tail > head) && list[tail] >=pivot)
       tail--;

    swap(list, head, tail); // Swap out-of-place values
  } while (head < tail); // Stop when they cross
  return head;  // Return first pos on right
}
void quickSort(int* list, int head, int tail) {
  if(head>=tail) return;
  int pivot;
  pivot = findPivot(head, tail);
  //pivot to the end for the convience of swaping data
  swap(list, pivot, tail);
  
  int k = partition(list, head, tail, list[pivot]);
  //pivot change back to right place
  swap(list, k, tail);
  
  quickSort(list, head, k-1);
  quickSort(list, k+1, tail);
}

void mergeSort(int* list, int* temp, int start, int end) {
  if(start == end) return;
  int mid = (start+end)/2;
  mergeSort(list, temp, start, mid);
  mergeSort(list, temp, mid+1, end);
  int i, j;
  //copy data to temp array
  for(i=start;i<=mid;i++)
    temp[i] = list[i];
  for(j = 1;j<=end-mid;j++)
    temp[mid+j] = list[end-j+1];
  // sort by comparing and copying data to original array
  int k;
  for(i=start,j=end,k=start;k<=end;k++)
  {
    if(temp[i]<temp[j])
      list[k] = temp[i++];
    else
      list[k] = temp[j--];
  }
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 23, 4, 5, 56, 20, 12, 34, 3, 9};
	int temp[10];
	// insertSort(arr, 10);
	// for(int i=0;i<10;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;
	// bubbleSort(arr, 10);
	// for(int i=0;i<10;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;
	// selectSort(arr, 10);
	// for(int i=0;i<10;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;
	shellSort(arr, 10);
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}