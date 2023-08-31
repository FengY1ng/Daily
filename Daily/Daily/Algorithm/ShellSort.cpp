//希尔排序

#include <iostream>
#include <vector>

using namespace std;

void ShellSort(vector<int> &arr)
{
    int len = arr.size();
    int gap = len / 2;
    while (gap > 0)
    {
        for (int i = gap; i < len; i++)
        {
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
}

int main()
{
    vector<int> arr = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    cout<<"Hello World"<<endl;
    cout << endl;
    return 0;
}
