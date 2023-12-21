#include <math.h>
#include "gauss.h"

int switch_rows(Matrix* mat, Matrix* b, int row_a, int row_b) {
    if(mat->r != b->r)
        return 2;
    if(mat->r - 1 < row_a || mat->r - 1 < row_b)
        return 1;
    double tmp;
    int i;
    for(i = 0; i < mat->c; i++) {
        tmp = mat->data[row_a][i];
        mat->data[row_a][i] = mat->data[row_b][i];
        mat->data[row_b][i] = tmp;
    }
    tmp = b->data[row_a][0];
    b->data[row_a][0] = b->data[row_b][0];
    b->data[row_b][0] = tmp;
    return 0;
}

int eliminate(Matrix* mat, Matrix* b) {
    int i, j, k;
    double tmp;
    if(mat->r != mat->c || mat->r != b->r)
        return 2;
    int s = mat->r;
    int max_index;
    double max_value;

    for(k = 0; k < s; k++) {
        for(j = s - 1; j > k; j--) {
            max_index = k;
            max_value = mat->data[k][k];
            for(i = k + 1; i < s; i++) {
                tmp = fabs(mat->data[i][k]);
                if(max_value > tmp)
                    continue;
                max_index = i;
                max_value = tmp;
            }
            if(max_index != k)
                switch_rows(mat, b, k, max_index);
            if(mat->data[k][k] == 0)
                return 1;
            tmp = mat->data[j][k] / mat->data[k][k];
            for(i = 1; i < s; i++) {
                mat->data[j][i] -= tmp * mat->data[k][i];
            }
            b->data[j][0] -= tmp * b->data[k][0];
            mat->data[j][k] = 0;
        }
    }

    return 0;
}
