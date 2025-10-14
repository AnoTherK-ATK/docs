//hàm xây dựng heap
void heapify(int B[], int i, int n){
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && a[l] > a[mx])
        mx = l;
    if(r < n && a[r] > a[mx])
        mx = r;
    //nếu node cha không phải lớn nhất, xây dựng lại cây con
    if(mx != i){ 
        std::swap(a[mx], a[i]);
        heapify(B, mx, n);
    }
}
