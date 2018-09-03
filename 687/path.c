int solution(int A[], int N, int E[], int K) {
    // write your code in C99 (gcc 6.2.0)
    
    if (N == 0) {
        return 0;
    }
		
	const int maxn = 1000;
	int mat[maxn][maxn];
	int degree[maxn], state[maxn], queue[maxn], length[maxn];
	int maxlen = 0;

    // Initialization.
	memset(mat, -1, sizeof(mat));      // neighbour table.
	memset(degree, 0, sizeof(degree)); // number of neighbours for each node.
	memset(state, 0, sizeof(state));   // BFS states.
	memset(length, 0, sizeof(length)); // BFS depths.

    // Set the node index starting from 0.
	for (int i = 0; i < K; ++i) {
		--E[i];
	}	

    // Build the neighbour table. 
	for (int i = 0; i < K; i += 2){
		int x = E[i]; 
		int y = E[i + 1];
		
		if (A[x] == A[y]) {
			mat[x][degree[x]++] = y;
			mat[y][degree[y]++] = x;
		}
	}

    // Start travesing the DAG.
	for (int i = 0; i < N; ++i) {
	    // Skip if the node was visited.
		if (state[i] != 0) {
		    continue;
		}

        // BFS and find one end of the longest path in the connected sub DAG.
		queue[0] = i;
		state[i] = 1;
		int head = 1, curr = 0;
		
		while (head > curr) {
			int node = queue[curr];
			
			for (int j = 0; j < degree[node]; j++) {
				int newNode = mat[node][j];
				
				if (state[newNode] != 1) {
					queue[head++] = newNode;
					state[newNode] = 1;
				}
			}
			curr++;
		}

        // Set the one end as the starting point to find another end of 
        // the longest path using BFS.
		int terminal = queue[curr - 1]; 

		queue[0] = terminal;
		state[terminal] = 2;
		head = 1; 
		curr = 0;
		
		while (head > curr) {
			int node = queue[curr];
			
			for (int j = 0; j < degree[node]; j++) { 
				int newNode = mat[node][j];
				if (state[newNode] != 2) {
					queue[head++] = newNode;
					state[newNode] = 2;
					length[newNode] = length[node] + 1;
				}
			}
			curr++;
		}

		terminal = queue[curr - 1];
		
		// Compare the length of this connected sub DAG with the current max length found
		if (length[terminal] > maxlen) {
		    maxlen = length[terminal];
		}	
	}
	
	return maxlen;
}