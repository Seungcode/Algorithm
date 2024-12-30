#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF	20001

#define MIN(x, y)	(((x) < (y))? (x) : (y))
#define MAX(x, y)	(((x) > (y))? (x) : (y))

int N, T, W;
int dy[10002][3];
int val[10002][2];

enum{fir, sec, whl};

void logic1(const int st) {
	for (int i = st; i <= N; i++) {
		int fir_fill = (val[i][fir] + val[i - 1][fir] <= W) ? 1 : 2;
		int sec_fill = (val[i][sec] + val[i - 1][sec] <= W) ? 1 : 2;
		int whl_fill = (val[i][fir] + val[i][sec] <= W) ? 1 : 2;

		dy[i][fir] = MIN(dy[i - 1][whl] + 1, dy[i - 1][sec] + fir_fill);
		dy[i][sec] = MIN(dy[i - 1][whl] + 1, dy[i - 1][fir] + sec_fill);

		dy[i][whl] = MIN(dy[i][fir] + 1, dy[i][sec] + 1);
		dy[i][whl] = MIN(dy[i][whl], dy[i - 1][whl] + whl_fill);
		dy[i][whl] = MIN(dy[i][whl], dy[i - 2][whl] + fir_fill + sec_fill);
	}
	return;
}

int main(void) {
	int valt;
	scanf("%d", &T);
	for (int hg = 0; hg < T; hg++) {
		memset(val, 0, sizeof(val));
		memset(dy, 0, sizeof(dy));

		scanf("%d %d", &N, &W);
		for (int i = 1; i <= N; i++) { scanf("%d", &val[i][fir]); }
		for (int i = 1; i <= N; i++) { scanf("%d", &val[i][sec]); }

		if (N == 1) {
			printf("%d\n", (val[1][fir] + val[1][sec] <= W) ? 1 : 2);
			continue;
		}

		dy[1][fir] = dy[1][sec] = 1;
		dy[1][whl] = ((val[1][fir] + val[1][sec]) <= W) ? 1 : 2;
		logic1(2);
		valt = dy[N][whl];

		dy[0][whl] = INF;
		if (val[1][fir] + val[N][fir] <= W) {

			dy[1][fir] = 1;
			dy[1][sec] = INF;
			dy[1][whl] = 2;
			logic1(2);

			valt = MIN(valt, dy[N][sec]);
		}

		if (val[1][sec] + val[N][sec] <= W) { //not else if
			dy[1][fir] = INF;
			dy[1][sec] = 1;
			dy[1][whl] = 2;
			logic1(2);

			valt = MIN(valt, dy[N][fir]);
		}

		if ((val[1][fir] + val[N][fir] <= W) && (val[1][sec] + val[N][sec] <= W)) { //unoptimizationed
			dy[1][fir] = dy[1][sec] = INF;
			dy[1][whl] = 2;
			logic1(2);

			valt = MIN(valt, dy[N - 1][whl]);
		}

		printf("%d\n", valt);
	}
	return 0;
}
