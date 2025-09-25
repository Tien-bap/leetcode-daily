int minValue(int a, int b){
    return a < b ? a : b;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    if(triangleSize == 1) return triangle[0][0];

    
    triangle[1][0] += triangle[0][0];
    triangle[1][1] += triangle[0][0];
    if(triangleSize == 2) return minValue(triangle[1][0], triangle[1][1]);

    int result = 100000000;
    for(int i = 2; i < triangleSize; i++){
        for(int j = 0; j < triangleColSize[i]; j++){
            if(j == 0)  triangle[i][j] += triangle[i-1][j];
            else if(j == triangleColSize[i] - 1) triangle[i][j] += triangle[i-1][j - 1];
            else triangle[i][j] += minValue(triangle[i-1][j], triangle[i-1][j - 1]);
            if(i == triangleSize -1) result = result < triangle[i][j] ? result : triangle[i][j];
        }
    }
    return result;
}
