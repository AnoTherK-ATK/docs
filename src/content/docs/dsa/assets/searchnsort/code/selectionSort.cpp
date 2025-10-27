void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int indexMin = 0;
        for(int j = i; j < n; j++){
            if(a[j] < a[indexMin])
                indexMin = j;
        }
        std::swap(a[i], a[j]);
    }
}
