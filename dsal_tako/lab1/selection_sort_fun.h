void Swap(int arr[], int x, int y)
{
	int t = arr[x];
	arr[x] = arr[y];
	arr[y] = t;
}

void SelectionSort(int arr[], int n)
{
	int pass, j, min_indx;
	for(pass = 0; pass < n-1; pass++)
	{
	    min_indx = pass;
	    for(j=pass+1; j<n; j++)
	        if(arr[j]<arr[min_indx])
	            min_indx = j;
	    if(min_indx != pass)
	        Swap(arr, min_indx, pass);
	}
}