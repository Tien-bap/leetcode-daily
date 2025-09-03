typedef struct{
    int x;
    int y;
}Point;

int cmp(const void*a, const void*b){
    int xa = ((Point*)a)->x;
    int ya = ((Point*)a)->y;
    int xb = ((Point*)b)->x;
    int yb = ((Point*)b)->y;
    if(xa == xb) return yb - ya < 0 ? -1 : 1;
    return xa - xb < 0 ? -1 : 1;
}

int check(Point* arr, int a, int b){
    int max = arr[a].y;
    int min = arr[b].y;
    for(int i = a+1; i < b; i++){
        if(arr[i].y <= max && arr[i].y >= min) return 0;
    }
    return 1;
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    Point* arr = (Point*)malloc(sizeof(Point)*pointsSize);
    for(int i = 0; i < pointsSize; i++){
        arr[i].x = points[i][0];
        arr[i].y = points[i][1];
    }
    qsort(arr, pointsSize,sizeof(Point),  cmp);

    int count = 0;
    for(int i = 0; i < pointsSize; i++){
        for(int j = i+1; j < pointsSize; j++){
            if(arr[i].y >= arr[j].y){
                if(check(arr, i, j)) count ++;
            }
        }
    }
    free(arr);

    return count;
}
