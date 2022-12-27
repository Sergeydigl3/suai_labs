#include <iostream>
#include <stdio.h>
using namespace std;
void rucksack(int* w, int* c, int v, int cur_v, int* set, int n, int cur_i, int cur_val, int& max_val, int* max_set){
	//n is the number of items
	//v is the capacity of the rucksack
	//w is an array of weights
	//c is an array of costs
	//cur_v is the current capacity of the rucksack
	//cur_i is the current item being considered
	//cur_val is the current value of the rucksack
	//max_val is the maximum value of the rucksack
	//set is an array of the number of each item
	//max_set is an array of the maximum number of each item
	if(v == 0 || cur_i == n){
		//if there is no more capacity or no more items, check if the current value is greater than the maximum value
		if(cur_val > max_val){
			//if it is, set the maximum value to the current value
			max_val = cur_val;
			//and set the maximum set to the current set
			for(int k = 0; k < n; k++){
				max_set[k] = set[k];
				//cout << set[k] << ' ';
			}
			//cout << ": " << *max_val << endl;
		}
	}
	else{
		//if there is still capacity and items to consider
		for(int i = 0; i <= v / w[cur_i]; i++){
			//for each item, check the value of all possible combinations of that item
			cur_v += w[cur_i] * i;
			cur_val += c[cur_i] * i;
			set[cur_i] = i;
			//recursively call the function to check the next item
			rucksack(w, c, v - w[cur_i] * i, cur_v, set, n, cur_i + 1, cur_val, max_val, max_set);
			//then set the current value and set back to the values before the function call
			set[cur_i] = 0;
			cur_v -= w[cur_i] * i;
			cur_val -= c[cur_i] * i;
		}
	}
}

int main(){
	int n = 7;
	int w[] = {3, 4, 2, 3, 5, 2, 4};
	int c[]   = {11, 20, 17, 32, 1, 10, 20};

	int max_value = 0;
	int* set = new int[n];
	int* max_set = new int[n];
	for(int i = 0; i < n; i++){
		set[i] = max_set[i] = 0;
	}
	int i, v;
	cout << "V = ";
	cin >> v;
    // Что такое V?
    // Это вместимость рюкзака.
    // V = 10
	rucksack(w, c, v, 0, set, n, 0, 0, max_value, max_set);
	for(int k = 0; k < n; k++)
		cout << max_set[k] << ' ';
	cout << endl;
	delete set;
	delete max_set;
}