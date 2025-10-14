std::priority_queue<int> mx; //max heap
std::priority_queue<int, std::vector<int>, std::greater<int> > mn;// min heap

for(int i = 0; i < n; i++){
    mn.push(a[i]);
}

while(!mn.empty()){
    int x = pq.top();
    pq.pop();
    //làm gì với x thì tuỳ, mảng đã được sắp xếp
}
