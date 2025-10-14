void quickSort(int a[], int left, int right){
    int i = left, j = right;
    int pivot = a[left + std::rand() % (right - left)]
    while(i <= j){
        while(a[i] < pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i <= j){
            std::swap(a[i], a[j]);
            i++;
            --j;
        }
    }
    if(left < j)
        quickSort(a, left, j);
    if(i < right)
        quickSort(a, i, right);
}
