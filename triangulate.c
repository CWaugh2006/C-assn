#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2){
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}


int checkIntersect(float x1, float y1, float r1, float x2, float y2, float r2){
    float d = distance(x1, y1, x2, y2);
    if(d <= r1 + r2){
        return 1;
    }
    return 0;
}
int checkTriangulate(float x1, float y1, float r1, float x2, float y2, float r2, float x3, float y3, float r3){
    if(checkIntersect(x1, y1, r1, x2, y2, r2) && checkIntersect(x1, y1, r1, x3, y3, r3) && checkIntersect(x2, y2, r2, x3, y3, r3)){
        return 1;
    }
    return 0;
}

int triangulate(float x1, float y1, float r1, float x2, float y2, float r2, float x3, float y3, float r3, float *x, float *y){
    if(checkTriangulate(x1, y1, r1, x2, y2, r2, x3, y3, r3) == 1){  
        float a1 = 2 * (x2 - x1);
        float b1 = 2 * (y2 - y1);
        float c1 = r1 * r1 - r2 * r2 - x1 * x1 + x2 * x2 - y1 * y1 + y2 * y2;
        
        float a2 = 2 * (x3 - x1);
        float b2 = 2 * (y3 - y1);
        float c2 = r1 * r1 - r3 * r3 - x1 * x1 + x3 * x3 - y1 * y1 + y3 * y3;
        if(b1 == 0){
            *x = c1 / a1;
            *y = (c2 - a2 * (*x)) / b2;
        } else if(b2 == 0){
            *x = c2 / a2;
            *y = (c1 - a1 * (*x)) / b1;
        } else {
            float mult = b2 / b1;
            float a1p = a1 * mult;
            float b1p = b1 * mult;
            float c1p = c1 * mult;
        }
        printf("x: %f, y: %f\n", *x, *y);
    }
    else{
        printf("No triangulation possible\n");
    }
    return 1;

}

int main(int argc, char ** argv){
    float x1, y1, r1, x2, y2, r2, x3, y3, r3 = 0;
    scanf("%f %f %f %f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2, &x3, &y3, &r3);
    float points[] = {x1, y1, r1, x2, y2, r2, x3, y3, r3};
    float x, y = 0;
    triangulate(x1, y1, r1, x2, y2, r2, x3, y3, r3, &x, &y);
    return EXIT_SUCCESS;
}



