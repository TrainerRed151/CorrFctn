// Copyright © 2016 Brian Pomerantz. All Rights Reserved.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inDist(double x, double y, double r, double dr);
double ran();

int main(int argc, const char *argv[]) {
    int np = 1000;
    double rmax = sqrt(2.0);
    double dr = 0.01;
    //int rsize = int(rmax/dr) + 1;
    int rsize = 100;
    FILE *opf = fopen("gr.dat", "w");
    if (opf == NULL) {
        printf("Can't open file gr.dat");
        return 2;
    }

    double r[rsize], x[np], y[np];
    int gr[rsize];

    int i, j, k;
    for (i = 0; i < rsize; i++) {
        r[i] = (rmax/rsize)*i;
        gr[i] = 0;
    }
    
    for (i = 0; i < np; i++) {
        if (ran() < 0.5) {
            x[i] = ran();
        }
        else {
            x[i] = -ran();
        }

        if (ran() < 0.5) {
            y[i] = ran();
        }
        else {
            y[i] = -ran();
        }
    }

    for (i = 0; i < rsize; i++) {
        for (j = 0; j < np; j++) {
            for (k = 0; k < np; k++) {
                gr[i] += inDist(x[j], y[k], r[i], dr);
            }
        }
        
        fprintf(opf, "%f, %d\n", r[i], gr[i]);
    }

    fclose(opf);
    
    return 0;
}

int inDist(double x, double y, double r, double dr) {
    double dist = sqrt(x*x + y*y);
    return (dist > (r - dr/2)) && (dist < (r + dr/2));
}

double ran() {
    return rand()/((double) RAND_MAX);
}
