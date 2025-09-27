double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double result = 0.0;
    double area;
    for(int i = 0; i < pointsSize; i++){
        for(int j = i + 1; j < pointsSize; j++){
            for(int k = j + 1; k < pointsSize; k++){
                area = 0.5 * abs(points[i][0]*(points[j][1]-points[k][1]) + points[j][0]*(points[k][1]-points[i][1]) + points[k][0]*(points[i][1]-points[j][1]));
                result = result > area ? result : area;
            }
        }
    }
    return result;
}
