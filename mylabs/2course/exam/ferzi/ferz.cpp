#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool check(int** desk, int n, int i, int j){
	int k, tmp_i1, tmp_i2, tmp_j;
	// проверка строк не нужна, т.к. в столбце мб только один ферзь
	for(k = 0; k < j; k++){ // проверка столбцов
		if(desk[i][k] == 1)
			return 0;
	}
	tmp_i1 = i - 1;
	tmp_j = j - 1;
    // что такое tmp_i1, tmp_i2, tmp_j? и почему вычетаешь 1?
    // tmp_i1, tmp_i2 - индексы строк, tmp_j - индекс столбца
    // вычитаю 1, т.к. в цикле проверяю диагонали, которые находятся слева от ферзя

    // Идем по столбцу вверх, пока не выйдем за границы доски
    // или не встретим ферзя
	while(tmp_i1 >= 0 && tmp_j >= 0){ // проверка диагонали "\"
		if(desk[tmp_i1][tmp_j] == 1)
			return 0;
		tmp_i1--;
		tmp_j--;
	}
	tmp_i2 = i + 1;
	tmp_j = j - 1;
	while(tmp_i2 < n && tmp_j >= 0){ // проверка диагонали "/"
		if(desk[tmp_i2][tmp_j] == 1)
			return 0;
		tmp_i2++;
		tmp_j--;
	}
	return 1;
}
int pherz(int** desk, int* index, int j, int n){
	int counter = 0;
	if(j >= n){ // если перебрали все столбцы
		// for(int k = 0; k < n; k++)
		// 	cout << index[k];
		// cout << endl;
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < n; j++){
		// 		cout << desk[i][j];
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		return 1;
	}
	else{
		for(int i = 0; i < n; i++){ // иначе перебираем строки
			if(check(desk, n, i, j)){ // если ферзь может стоять на клетке
				desk[i][j] = 1; // ставим ферзя
				index[j] = i; // записываем индекс строки
				counter += pherz(desk, index, j + 1, n); // идем дальше
				desk[i][j] = 0; // возвращаем доску в исходное состояние
				index[j] = 0; // возвращаем индекс строки в исходное состояние
			}
		}
		return counter;
	}
}
int main(){
	int** desk;
	int* index;
    // что такое index?
    // index - массив индексов, в которых стоят ферзи
    // index[i] - индекс строки, в которой стоит ферзь в i-м столбце

	int n, i, j;
	cout << "n = ";
	cin >> n;
	index = new int[n];
	desk = new int*[n];
	for(i = 0; i < n; i++){
		desk[i] = new int[n];
		for(j = 0; j < n; j++){
			desk[i][j] = 0;
			index[j] = 0;
		}
	}
	cout << "Amount = "<< pherz(desk, index, 0, n) << endl;
	for(i = 0; i < n; i++)
		delete[] desk[i];
	delete desk;
	delete index;
}
