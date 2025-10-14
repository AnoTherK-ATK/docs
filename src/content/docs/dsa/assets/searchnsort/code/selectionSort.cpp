void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int indexMin = std::min_element(a + i, a + n) - a;
        std::swap(a[i], a[indexMin]);
    }
}
