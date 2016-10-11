// Copyright © 2016 Brian Pomerantz. All Rights Reserved.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inDist(double x, double y, double r, double dr);

int main(int argc, const char *argv[]) {
    int np = 10;
    double rmax = sqrt(2.0);
    double dr = 0.01;
    //int rsize = int(rmax/dr) + 1;
    int rsize = 100;

    double r[rsize], x[np], y[np];

    int i, j;
    for (i = 1; i < rsize; i++) {
        r[i] = (rmax/rsize)*i;
    }
    
    for (i = 0; i < np; i++) {
        if (rand() < 0.5) {
            x[i] = rand();
        }
        else {
            x[i] = -rand();
        }

        if (rand() < 0.5) {
            y[i] = rand();
        }
        else {
            y[i] = -rand();
        }
    }

    for (i = 0; i < rsize; i++) {
        
    }

    
    return 0;
}

int inDist(double x, double y, double r, double dr) {
    double dist = sqrt(x*x + y*y);
    return dist > r - dr/2 && dist < r + dr/2;
}
