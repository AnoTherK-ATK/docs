void heapSort(int B, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(B, i, n);
    for(int i = n - 1; i > 0; i--){
        swap(B[0], B[i]);
        heapify(B, 0, i);
    }
}
