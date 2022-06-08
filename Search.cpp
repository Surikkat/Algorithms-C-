
//Обычный линейный поиск числа v в массиве целых чисел от l до r
//В худшем случае N сравнений, а в среднем N/2
int search(int a[], int v, int l, int r) 
{
		for (int i = l; i <= r; ++i) {
			if (v = a[i]) {
				return i;
			}
		}
		return -1;
}

//Бинарный поиск числа v в отсортированном массиве целых чисел от l до r
//Исследуется не более lg(N)+1 чисел
int binarySearch(int a[], int v, int l, int r) {
	while (r >= l) {
		int m = (l + r) / 2;
		if (v == a[m]) {
			return m;
		}
		if (v < a[m]) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
}