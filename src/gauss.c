#include "gauss.h"

int eliminate(Matrix* mat, Matrix* b) {
    int i, j, k;
    double tmp;
    if(mat->r != mat->c || mat->r != b->r)
        return 2;
    int s = mat->r;

    for(k = 0; k < s; k++) {
        for(j = s - 1; j > k; j--) {
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
