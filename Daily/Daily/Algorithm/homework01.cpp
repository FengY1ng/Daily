//设计一个算法，找出数组a[0:n-1]中元素的最大和最小值。

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
void MaxMin(T *A, int n, T &max, T &min)
{
    max = min = A[0];
    for (int i = 1; i < n; ++i)
    {
        if (A[i] > max)
            max = A[i];
        else if (A[i] < min)
            min = A[i];
    }
}

template <typename T>
void MaxMin2(T *A, int n, T &max, T &min)
{
    if (n % 2 == 0)
    {
        if (A[0] > A[1])
        {
            max = A[0];
            min = A[1];
        }
        else
        {
            max = A[1];
            min = A[0];
        }
        for (int i = 2; i < n; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > max)
                    max = A[i];
                if (A[i + 1] < min)
                    min = A[i + 1];
            }
            else
            {
                if (A[i + 1] > max)
                    max = A[i + 1];
                if (A[i] < min)
                    min = A[i];
            }
        }
    }
    else
    {
        max = min = A[0];
        for (int i = 1; i < n; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > max)
                    max = A[i];
                if (A[i + 1] < min)
                    min = A[i + 1];
            }
            else
            {
                if (A[i + 1] > max)
                    max = A[i + 1];
                if (A[i] < min)
                    min = A[i];
            }
        }
    }
}

template <typename T>
void MaxMin3(T *A, int n, T &max, T &min)
{
    if (n % 2 == 0)
    {
        if (A[0] > A[1])
        {
            max = A[0];
            min = A[1];
        }
        else
        {
            max = A[1];
            min = A[0];
        }
        for (int i = 2; i < n; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > max)
                    max = A[i];
                if (A[i + 1] < min)
                    min = A[i + 1];
            }
            else
            {
                if (A[i + 1] > max)
                    max = A[i + 1];
                if (A[i] < min)
                    min = A[i];
            }
        }
    }
    else
    {
        max = min = A[0];
        for (int i = 1; i < n; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > max)
                    max = A[i];
                if (A[i + 1] < min)
                    min = A[i + 1];
            }
            else
            {
                if (A[i + 1] > max)
                    max = A[i + 1];
                if (A[i] < min)
                    min = A[i];
            }
        }
    }
}
