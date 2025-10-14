void insertionSort(int a[], int n){
    for(int i = 1;i < n; i++){
        int x = a[i];
        int pos = i - 1;
        while(pos >= 0 && a[pos] > x){
            a[pos + 1] = a[pos]; // dời chỗ
            pos--;
        }
        a[pos + 1] = x;
    }
}
