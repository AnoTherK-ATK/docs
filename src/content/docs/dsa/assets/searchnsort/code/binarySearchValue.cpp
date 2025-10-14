int binarySearch(int n, int x){
    int l = 0, r = n - 1;
    int ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid <= x){
            ans = mid;
            l = mid + 1;
        }else
            r = mid - 1;
    }
    return ans;
}
