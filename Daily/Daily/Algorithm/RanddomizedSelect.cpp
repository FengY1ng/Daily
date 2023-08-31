#include <iostream>

using namespace std;

template <typename T>
T RandomizedSelect(T *A, int p, int r, int i)
{
    if (p == r)
        return A[p];
    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return RandomizedSelect(A, p, q - 1, i);
    else
        return RandomizedSelect(A, q + 1, r, i - k);
}

template <typename T>
int RandomizedPartition(T *A, int p, int r)
{
    int i = Random(p, r);
    swap(A[i], A[r]);
    return Partition(A, p, r);
}

template <typename T>
int Partition(T *A, int p, int r)
{
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j)
    {
        if (A[j] <= x)
        {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

template <typename T>
int Random(int p, int r)
{
    srand(time(NULL));
    return rand() % (r - p + 1) + p;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << RandomizedSelect(A, 0, 7, 3) << endl;
    return 0;
}