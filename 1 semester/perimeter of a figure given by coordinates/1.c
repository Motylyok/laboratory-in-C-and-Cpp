#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    float x, y, angle;
} Point;

int compareAngles(const void *a, const void *b) {
    return (*(Point *)b).angle > (*(Point *)a).angle ? 1 : (*(Point *)b).angle < (*(Point *)a).angle ? -1 : 0;
}

float calculateAndPrintPerimeter(const float input[], int numPoints) {
    Point vertices[numPoints];

    for (int i = 0; i < numPoints; ++i)
        vertices[i] = (Point){input[2 * i], input[2 * i + 1]};

    Point minYPoint = vertices[0];
    for (int i = 1; i < numPoints; ++i) {
        if (vertices[i].y < minYPoint.y) {
            minYPoint = vertices[i];
        }
    }

    for (int i = 0; i < numPoints; ++i)
        vertices[i].angle = atan2f(vertices[i].y - minYPoint.y, vertices[i].x - minYPoint.x);

    qsort(vertices, numPoints, sizeof(Point), compareAngles);

    float perimeter = 0.0f;
    for (int i = 0; i < numPoints; ++i) {
        float dx = vertices[(i + 1) % numPoints].x - vertices[i].x;
        float dy = vertices[(i + 1) % numPoints].y - vertices[i].y;
        perimeter += sqrtf(dx * dx + dy * dy);
    }


    return perimeter;
}

int main(void) {
    //  = {x0, y0, x1, y1, x2, y2, x3, ...}
    float rectangle[] = {1, 5, 7, 1, 7, 5, 1, 1};
    float star[] = {3.97, 0.82, 2.26, 3.69, 5.39,
                    2.16, 2.03, 2.11, 5.36, 4.06};
    float enneagon[] = {76, 67.1, -8.3, 18, 55,
                        93.3, 77, 33, 21.3, 99, -20,
                        50, -8.3, 82, 55, 6.7, 21.3, 0.76};

    float *shapes[] = {rectangle, star, enneagon};
    int sizes[] = {sizeof(rectangle) / sizeof(rectangle[0]),
                   sizeof(star) / sizeof(star[0]),
                   sizeof(enneagon) / sizeof(enneagon[0])};

    for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); ++i)
        printf("perimetr - %.3f\n", calculateAndPrintPerimeter(shapes[i], sizes[i] / 2));

    return 0;
}