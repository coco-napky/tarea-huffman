#include "Test.h"


void test()
{
    static const char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    static const int arr2[] = {5, 10, 12, 13, 19, 91};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

    map<char,string> res = getHuffman(vec, vec2);


    static const char arrx[] = {'x', 'y', 'z'};
    vector<char> vecx (arrx, arrx + sizeof(arrx) / sizeof(arrx[0]) );

    static const int arr2x[] = {5, 10, 15,};
    vector<int> vec2x (arr2x, arr2x + sizeof(arr2x) / sizeof(arr2x[0]) );

    map<char,string> resx = getHuffman(vecx, vec2x);

    if(res['f'] == "0"
       && res['c'] == "100"
       && res['d'] == "101"
       && res['a'] == "1100"
       && res['b'] == "1101"
       && res['e'] == "111"

       && resx['x'] == "10"
       && resx['y'] == "11"
       && resx['z'] == "0"
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
