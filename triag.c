#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ehTri(int i, int j, int k, int b, int n, int mat[n][n], int pad)
{
    if(b == 1)
        if(mat[i][j] == pad)
            return 1;
		else
			return 0;
    if(k == b)
        return ehTri(i - 1, j + 1, 0, b - 2, n, mat, pad);
    if(mat[i][j+k] == pad)
        return ehTri(i, j, k + 1, b, n, mat, pad);
    return 0;
}

int main() {
    int t, b, n, c = 0, i, j, tri1, tri0;
    scanf("%d\n", &t);
    while(c++ < t)
    {
        tri1 = 0;
        tri0 = 0;
        scanf("%d\n%d\n", &b, &n);
        int mat[n][n];
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        for(i = b / 2; i < n; i++)
            for(j = 0; j <= n - b; j++)
                if(ehTri(i, j, 0, b, n, mat, mat[i][j]))
                    if(mat[i][j] == 0)
                        tri0++;
                    else
                        tri1++;
        printf("Caso %d:\n%d triangulos formados por 1\n%d triangulos formados por 0\n", c, tri1, tri0);
    }
	return 0;
}
