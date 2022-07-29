#include <iostream>

using namespace std;

void swapp(char* a, char* b, size_t size_elem) {
    for (size_t i = 0; i < size_elem; i++)
    {
        char temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }
}

int comp_int(const char* pa, const char* pb) {
    int* a = (int*)pa;
    int* b = (int*)pb;
    return (*a - *b);
}

void buble_sort(void* arr, size_t n, size_t elemsize, int (*comp)(const char*, const char*)) {
    char* ar = (char*)arr;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (comp(ar + elemsize * j, ar + elemsize * (j + 1)) > 0)
                swapp(ar + elemsize * j, ar + elemsize * (j + 1), elemsize);
        }
    }
}

void sel_sort(void* arr, size_t n, size_t elemsize, int (*comp)(const char*, const char*) ){
    char* ar = (char*)arr;

    for (size_t i = 0; i < n - 1; i++)
    {
        int min_id = i;
        for (size_t j = i; j < n; j++)
        {
            if (comp(ar + elemsize * min_id, ar + elemsize * j) > 0)
                min_id = j;
        }
        swapp(ar + elemsize * i, ar + elemsize * min_id, elemsize);
    }
}

void insertion_sort(void* arr, size_t n, size_t elemsize, int (*comp)(const char*, const char*)) {
    char* ar = (char*)arr;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (comp(ar + elemsize * j, ar + elemsize * (j-1)) < 0)
            {
                swapp(ar + elemsize * j, ar + elemsize * (j-1), elemsize);
            }
            
        }
        
    }

}

int main(int argc, char const* argv[])
{
    int vector[] = { 14, 10, 11, 19, 2, 25 };
    size_t size = sizeof(vector) / sizeof(int);

    for (size_t i = 0;i < size;i++) cout << " " << vector[i];
    cout << endl;

    // buble_sort(vector, size, sizeof(int), comp_int);
    // sel_sort(vector, size, sizeof(int), comp_int);
    insertion_sort(vector, size, sizeof(int), comp_int);


    for (size_t i = 0;i < size;i++) cout << " " << vector[i];
    cout << endl;


    return 0;
}
