//QUICK SORT
int partition(std::vector<int> &arr, int low, int high){
  //partion function to help quickSort function
    int pivot = arr[high];    // pivot
    int i = (low - 1);

    for(int j = low; j <= high- 1; j++) if (arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    
    swap(&arr[i++], &arr[high]);
    return (i++);
}

void quickSort(std::vector<int> &arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
