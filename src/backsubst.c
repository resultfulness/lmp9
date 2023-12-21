#include "backsubst.h"

int backsubst(Matrix* x, Matrix* mat, Matrix* b) {
    if (x->c != 1 || x->r != mat->r ||
        b->c != x->c || b->r != x->r ||
        mat->r != mat->c) {
        return 2;
    }

    double root;
    int row = mat->r;

    while (row--) {
        if (mat->data[row][row] == 0) 
            return 1;
        root = b->data[row][0];
        for (int i = row + 1; i < mat->c; i++) {
            root -= mat->data[row][i] * x->data[i][0];
        }
        root /= mat->data[row][row];
        x->data[row][0] = root;
    }

    return 0;
}
