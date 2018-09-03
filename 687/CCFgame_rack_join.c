#include <stdio.h>
#include <string.h>

int main()
{

	//int A[] = {1000000000, 1000000000, 1000000000, 2, 2};
	//int E[] = {1,2,1,3,2,4,2,5};
	//printf("-2\n");
	
	int A[] = {1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1};
	int E[] = {2, 7, 10, 4, 3, 11, 8, 6, 2, 6, 1, 2, 4, 12, 11, 4, 5, 10, 9, 5, 4, 2};
	int N = 12;
	int K = 22;

	if (N == 0)
		return 0;

	
	//printf("-1\n");



	const int maxn = 1000;
	int mat[maxn][maxn];
	int degree[maxn], state[maxn], queue[maxn], length[maxn];
	int maxlen = 0;

	//printf("0\n");


	memset(mat, -1, sizeof(mat));
	memset(degree, 0, sizeof(degree));
	memset(state, 0, sizeof(state));
	memset(length, 0, sizeof(length));

	//printf("1\n");

	for (int i = 0; i < K; ++i) {
		--E[i];
	}	

	for (int i = 0; i < K; i += 2){
		int x = E[i]; 
		int y = E[i + 1];
		if (A[x] == A[y]) {
			mat[x][degree[x]++] = y;
			mat[y][degree[y]++] = x;
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("%d", degree[i]);
		printf("\n");
	}*/

	for (int i = 0; i < N; ++i) {
		if (state[i] != 0) continue;

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

		//printf("queue length: %d\n", curr);
		//printf("queue: "); for (int j = 0; j < n; j++) printf("%d ", queue[j]); printf("\n");
		//printf("state: "); for (int j = 0; j < n; j++) printf("%d ", state[j]); printf("\n");
		


		int terminal = queue[curr - 1]; 
		//printf("terminal: %d\n", terminal);

		queue[0] = terminal;
		state[terminal] = 2;
		head = 1; curr = 0;
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

		//printf("queue length: %d\n", curr);
		//printf("queue: "); for (int j = 0; j < n; j++) printf("%d ", queue[j]); printf("\n");
		//printf("state: "); for (int j = 0; j < n; j++) printf("%d ", state[j]); printf("\n");
		//printf("length: "); for (int j = 0; j < n; j++) printf("%d ", length[j]); printf("\n");
		terminal = queue[curr - 1];
		if (length[terminal] > maxlen) 
			maxlen = length[terminal];
		//printf("terminal: %d\n\n\n", terminal);
	}
	printf("%d\n", maxlen);

	return maxlen;
}