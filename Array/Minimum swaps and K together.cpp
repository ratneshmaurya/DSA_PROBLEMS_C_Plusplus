int minSwap(int arr[], int n, int k) {
        // Complet the function
        
        // first counting all numbers which are close to k
        int i,count=0;
        for(i=0;i<n;i++){
            if(arr[i]<=k) count++;
        }
        i=0;
        // now counting the numbers which are not close to 'k'
        int unclose;
        for(i=0;i<count;i++){
            if(arr[i]>k)
                unclose++;
        }

        // now sliding window technique
        int j,min_swap=unclose;
        min_swap=min(unclose,min_swap);
        for(i=0,j=count;j<n;i++,j++){
            if(arr[j]>k) unclose++;
            if(arr[i]>k) unclose--;
            min_swap=min(unclose,min_swap);
        }
        return min_swap;
    }