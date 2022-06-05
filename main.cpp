#include <iostream>

//Задача связности методом быстрого поиска в одномерном массиве
//Два объекта p и q связанны, если id[p]==id[q]
//>M*N/2 инструкций, где M-кол ребер, а N - количество объектов (ВСЕГДА)
void ConnectivityByFastSearchMethod() {
	static const int N = 10000;
	int p, q, id[N];

	for (int i = 0; i < N; ++i) {
		id[i] = i;
	}

	while (std::cin >> p >> q) {
		if (id[p] == id[q]) {
			continue;
		}
		for (int i = 0; i < N; ++i) {
			if (id[i] == id[p]) {
				id[i] = id[q];
			}
		}
		std::cout << " " << p << " " << q << std::endl;
	}
}

//Задача связности методом быстрого объединения
//Два объекта p и q связанны, если принадлежат одному и тому же дереву (у них один и тот же корень)
//>M*N/2 инструкций, где M-кол ребер, а N - количество объектов (ИНОГДА)
void ConnectivityByFastUnionMethod() {
	static const int N = 10000;
	int p, q, id[N];

	for (int i = 0; i < N; ++i) {
		id[i] = i;
	}

	int i,j;
	while (std::cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j) {
			continue;
		}
		id[i] = j;
		std::cout << " " << p << " " << q << std::endl;
	}
}

//Задача связности методом быстрого взвешенного объединения (Объединяем меньшее дерево с большим)
//Два объекта p и q связанны, если принадлежат одному и тому же дереву (у них один и тот же корень)
//Для определения связности в массиве из N объектов в худшем случае (lg(N) указателей)
//<M*N инструкций, где M-кол ребер, а N - количество объектов
void ConnectivityByFastUnionWeightedMethod() {
	static const int N = 10000;
	int p, q, id[N], i, j, sz[N];
	for (i = 0; i < N; ++i) {
		id[i] = i;
		sz[i] = 1;
	}

	while (std::cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j) {
			continue;
		}
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		std::cout << " " << p << " " << q << std::endl;
	}
}


int main() 
{
	ConnectivityByFastUnionWeightedMethod();

	return 0;
}