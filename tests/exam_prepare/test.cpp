
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string base = "❤️💛💚💙💜🖤🤍🤎❤️‍🔥❣️💕💞💓💗💖💘💝💟";
    srand(time(NULL));
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cout << base[rand()%base.size()]<< "\t";
    }
    
    return 0;
}
