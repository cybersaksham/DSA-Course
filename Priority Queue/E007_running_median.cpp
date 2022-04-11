void findMedian(int *arr, int n) {
    // Write your code here
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    for(int i=0; i<n; i++) {
    	int a = pq1.front();
    	int b = pq2.front();
    	if(pq1.size() == 0) a = -1;
    	if(pq2.size() == 0) b = -1;
    	
    	if(a == -1) pq1.push(arr[i]);
    	else if(arr[i] > a) pq2.push(arr[i]);
    	else pq1.push(arr[i]);
    	
    	int m = pq1.size(), n = pq2.size();
    	if(m > n + 1) {
    		int k = pq1.top();
    		pq1.pop();
    		pq2.push(k);
    		m--;
    		n++;
    	}
    	else if(n > m + 1) {
    		int k = pq2.top();
    		pq2.pop();
    		pq1.push(k);
    		m++;
    		n--;
    	}
    	
    	a = pq1.front();
    	b = pq2.front();
    	if(a == -1) cout << b << " ";
    	else if(b == -1) cout << a << " ";
    	else if((m + n) % 2 == 0) cout << ((a + b) / 2) << " ";
    	else if(m < n) cout << b << " ";
    	else cout << a << " ";
    }
    
    cout << endl;
}
