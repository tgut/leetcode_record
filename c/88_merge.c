

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
int sum=0,i=0,j=0,count=0;
    sum = m+n;
    int *store;
    store = (int*)malloc(sum*sizeof(int));
    if( n == 0){
        return;
    }
    if(m == 0){
        for(j=0;j<n;j++)
            nums1[j]=nums2[j];
        return;
    }
        
    for(count=0;count<sum;count++)
    {
        if(nums1[i]<= nums2[j] && i < m ){
            store[count]=nums1[i];
            i++;
        }
        else if(j < n){
            store[count]=nums2[j];
            j++;
        }
        if(i==m || j==n)
            break;
    }
    if( i == m && j ==n ){
        for(i=0; i< sum ; i++)
            nums1[i]= store[i];

        return;
    }

    if(i==m){
        for(;j<n;j++,count++){
            store[count]=nums2[j];
        }
    }
    if(j==n){
        for(;i<m;i++,count++){
            store[count]=nums1[i];
        }
    }

    for(i=0; i< sum ; i++)
            nums1[i]= store[i];
}

