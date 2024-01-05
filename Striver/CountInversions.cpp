// whenever we need to count inversions, use merge sort
void merge(int low, int mid, int high, vector<int>& a, int& count) {
    int i=low, j=mid+1;
    while(i<=mid) {
        while(j<=high && a[i] > a[j]) {
            j++;
        }
        count += (j-mid-1);
        i++;
    }
    i=low;
    j=mid+1;
    vector<int> tem;
    while(i<=mid && j<=high) {
        if(a[i]<=a[j]) {
            tem.push_back(a[i++]);
        } else {
            tem.push_back(a[j++]);
        }
    }
    while(i<=mid) {
        tem.push_back(a[i++]);
    }
    while(j<=high) {
        tem.push_back(a[j++]);
    }
    for(int i=low; i<=high; i++) {
        a[i] = tem[i-low];
    }
}

void mergeSort(int low, int high, vector<int>& a, int& count) {
    if(low>=high) return;
    int mid = low+(high-low)/2;

    mergeSort(low, mid, a, count);
    mergeSort(mid+1, high, a, count);
    merge(low, mid, high, a, count);
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    // int n=a.size();
    int count=0;
    mergeSort(0, n-1, a, count);
    
    return count;
}
