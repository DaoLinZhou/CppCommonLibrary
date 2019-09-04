//
// Created by Daolin on 2019/7/5.
//

#ifndef ALGORITHM_COUNTINGSORT_H
#define ALGORITHM_COUNTINGSORT_H

template <typename T>
void countingSort(T arr[], int n, int min, int max){
    T *aux = new T[(max-min+1)];
    for(int i=0; i<(max-min+1); i++)
        aux[i] = 0;
    for(int i=0; i<n; i++)
        aux[arr[i]-min]++;
    for(int i=0, index=0; i<(max-min+1); i++)
        for(int j=0; j<aux[i]; j++, index++)
            arr[index] = i+min;
    delete[](aux);
}

#endif //ALGORITHM_COUNTINGSORT_H
