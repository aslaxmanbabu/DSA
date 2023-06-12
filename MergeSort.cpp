#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftarr[n1], rightarr[n2]; 
    
    for(int i=0; i<n1; i++) {
        leftarr[i] = arr[left+i];
    }
    for(int j=0; j<n2; j++) {
        rightarr[j] = arr[mid+1+j];
    }
    
    int i = 0, j = 0, k = left; 
    
    while(i<n1 and j<n2) {
        if(leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        }
        else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    
    while(i<n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    
    while(j<n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int begin, int end) {
    
    if(begin >= end) {
        return ;
    }
    
    int mid = begin + (end-begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
    
}

void display(int arr[], int n) {
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Given array is: ";
    display(arr, n);
    
    mergeSort(arr, 0, n-1);
    
    cout<<endl<<"Sorted Array:   ";
    display(arr, n);

    return 0;
}

