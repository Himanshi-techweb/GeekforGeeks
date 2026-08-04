void swap(int *a,int *b){
    int x=*a;
    *a=*b;
    *b=x;
}
void insertionSort(int* arr, int n) {
    // Code here
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
           swap(&arr[j],&arr[j-1]);
           j--;
        }
    }
}
