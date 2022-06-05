#include <iostream>

//������ ��������� ������� �������� ������ � ���������� �������
//��� ������� p � q ��������, ���� id[p]==id[q]
//>M*N/2 ����������, ��� M-��� �����, � N - ���������� �������� (������)
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

//������ ��������� ������� �������� �����������
//��� ������� p � q ��������, ���� ����������� ������ � ���� �� ������ (� ��� ���� � ��� �� ������)
//>M*N/2 ����������, ��� M-��� �����, � N - ���������� �������� (������)
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

//������ ��������� ������� �������� ����������� ����������� (���������� ������� ������ � �������)
//��� ������� p � q ��������, ���� ����������� ������ � ���� �� ������ (� ��� ���� � ��� �� ������)
//��� ����������� ��������� � ������� �� N �������� � ������ ������ (lg(N) ����������)
//<M*N ����������, ��� M-��� �����, � N - ���������� ��������
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