#pragma once
//Обычный линейный поиск в массиве целых чисел
//В худшем случае N сравнений, а в среднем N/2
int search(int a[], int v, int l, int r);

//Бинарный поиск в отсортированном массиве
//Исследуется не более lg(N)+1 чисел
int binarySearch(int a[], int v, int l, int r);
