typedef struct{
    int pass;
    int total;
    double delta;
} Class;

double getDelta(int pass, int total){
    double new = (double)(pass+1)/(total+1);
    double present = (double)(pass)/(total);
    return new - present;
}

int cmp(const void*a, const void*b){
    double db = ((Class*)b)->delta;
    double da = ((Class*)a)->delta;
    if(db < da) return -1;
    else if(db > da) return 1;
    return 0;
}

void swap(Class*a, Class*b){
    Class temp = *a;
    *a = *b;
    *b = temp;
}

/// MaxHeap -----
typedef struct{
    Class* data;
    int capacity;
    int size;
} MaxHeap;

MaxHeap* createHeap(int capacity){
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (Class*)malloc(sizeof(Class)*capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void destroyHeap(MaxHeap*heap){
    if(heap){
        free(heap->data);
        free(heap);
    }
}

void heapifyUp(MaxHeap*heap, int index){
    int parent = (index -1)/2;
    while(index > 0 && heap->data[index].delta > heap->data[parent].delta){
        swap(&heap->data[index], &heap->data[parent]);
        index = parent;
        parent = (index -1)/2;
    }
}

void heapifyDown(MaxHeap*heap, int index){
    int leftChild, rightChild, largest;
    while(1){
        leftChild = 2*index + 1;
        rightChild = 2*index + 2;
        largest = index;

        if(leftChild < heap->size && heap->data[leftChild].delta > heap->data[largest].delta){
            largest = leftChild;
        }
        if(rightChild > heap->size && heap->data[rightChild].delta > heap->data[largest].delta){
            largest = rightChild;
        }

        if(largest == index) break;
        swap(&heap->data[index], &heap->data[largest]);
        index = largest;
    }
}

void push(MaxHeap*heap, Class element){
    if(heap->size == heap->capacity) return;
    heap->data[heap->size] = element;
    heapifyUp(heap, heap->size);
    heap->size ++;
}

Class pop(MaxHeap*heap){
    if(heap->size ==0) return;
    Class root = heap->data[0];
    heap->data[0] = heap->data[heap->size -1];
    heap->size --;
    heapifyDown(heap, 0);
    return  root;
}

/// MaxHeap -----

/// solve -----
double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    MaxHeap* heap = createHeap(classesSize);

    int pass;
    int total;
    double delta;
    for(int i = 0; i < classesSize; i++){
        pass = classes[i][0];
        total = classes[i][1];
        delta = getDelta(pass, total);
        push(heap, (Class){pass, total, delta});
    }

    while(extraStudents-- > 0){
        Class top = pop(heap);

        top.pass ++;
        top.total ++;
        top.delta = getDelta(top.pass, top.total);
        push(heap, top);
    }

    double result = 0;
    for(int i = 0; i < classesSize; i++){
        result += (double)heap->data[i].pass/heap->data[i].total;
    }
    destroyHeap(heap);
    return result/classesSize;
  }
