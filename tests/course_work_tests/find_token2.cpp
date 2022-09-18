#include <iostream>
#include <string>
using namespace std;


struct Symbol {
    int Symbol;
    int Count;
    int Code;
    int MyCode;
    int Bits;
    std::string StrCode;
};

// function to find index which split array into two closest groups
int split_2_groups(int arr[], int n)
{
    // initialize sum of whole array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        cout << arr[i] << " ";
    }


    // initialize left and right sums and minimum difference
    int lsum = 0, rsum = sum, diff = INT8_MAX;
    int min_index = 0;
    // traverse array from left to right
    for (int i = 0; i < n; i++)
    {
        // add current element to left sum
        lsum += arr[i];

        // subtract current element to right sum
        rsum -= arr[i];

        // update minimum difference
        if (abs(lsum - rsum) < diff) {
            diff = abs(lsum - rsum);
            min_index = i;
        }
    }
    cout << endl;
    // return minimum index
    return min_index;
    // return diff;
}


// split_2_groups function for Symbol struct
int split_2_groups(Symbol* sym, int from, int to)
{
    // initialize sum of whole array
    int sum = 0;
    for (int i = from; i < to; i++) {
        sum += sym[i].Count;
        // cout << sym[i].Count << " ";
    }
    // cout << endl;

    // initialize left and right sums and minimum difference
    int lsum = 0, rsum = sum, diff = INT8_MAX;
    int min_index = 0;
    // traverse array from left to right
    for (int i = from; i < to; i++)
    {
        // add current element to left sum
        lsum += sym[i].Count;

        // subtract current element to right sum
        rsum -= sym[i].Count;

        // update minimum difference
        if (abs(lsum - rsum) < diff) {
            diff = abs(lsum - rsum);
            min_index = i;
        }
    }
    cout << endl;
    // return minimum index
    return min_index;
}

int make_tree(Symbol* sym, int from, int to, std::string code)
{
    if(from+1 == to) {
        sym[from].StrCode = code;
        sym[from].MyCode = stoi(code);
        return 0;
    }


    int index = split_2_groups(sym, from, to)+1;

    // if (index + 1 == to || index == from){ 
    //     sym[from].MyCode = stoi(code);
    //     sym[from].StrCode = code;
    //     //sym[from].Bits = code.length();
    //     return 0;
    // }
    make_tree(sym, from, index, code + "0");
    make_tree(sym, index, to, code + "1");
    return 0;
}



int main(int argc, char const* argv[])
{
    int array[4] = { 4, 2, 1, 1 };
    Symbol sym[4];

    int array_size = sizeof(array) / sizeof(array[0]);

    int start = 0;
    int end = array_size - start;

    //fill array sym with array data to Count and set other to 0
    for (int i = 0; i < array_size; i++) {
        sym[i].Symbol = i;
        sym[i].Count = array[i];
        sym[i].Code = 0;
        sym[i].MyCode = 0;
        sym[i].Bits = 0;
    }

    make_tree(sym, 0, array_size, "");



    // print all str codes
    for (int i = 0; i < array_size; i++) {
        cout << sym[i].StrCode << " " << endl;
    }

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     Symbol sym[8];
//     int array[8] = { 4, 2, 1, 1,1,1,1,1 };

//     //fill array sym with 0, except Count from array;
//     for (int i = 0; i < 8; i++) {
//         sym[i].Symbol = i;
//         sym[i].Count = array[i];
//         sym[i].Code = 0;
//         sym[i].MyCode = 0;
//         sym[i].Bits = 0;
//     }


//     return 0;
// }
