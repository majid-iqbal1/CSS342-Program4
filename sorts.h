#ifndef SORT_H_
#define SORT_H_
#include <vector>
using namespace std;

void Merge(vector<int>& vec, int first, int mid, int last)
{
    int size = last - first + 1;
    int* temp_arr;
    temp_arr = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;
    
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[first2])
        {
            temp_arr[index] = vec[first1];
            first1++;
        }
        else
        {
            temp_arr[index] = vec[first2];
            first2++;
        }
        index++;
    }

    while(first1 <= last1)
    {
        temp_arr[index] = vec[first1];
        first1++;
        index++;
    }
    while(first2 <= last2)
    {
        temp_arr[index] = vec[first2];
        first2++;
        index++;
    }
    for(index = 0; index < size; index++)
    {
        vec[first] = temp_arr[index];
        first++;
    }
    delete[] temp_arr;
}

//Recursive merge sort inmplementation
void MergeSort(vector<int> & vec, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid+1, last);
        Merge(vec, first, mid, last);
    }
}

void InsertionSort(vector<int> & vec, int first, int last)
{
    //insertion sort algorithm
    for(int i = first + 1; i <= last; ++i)
    {
        int temp = vec[i];
        int j = i - 1;
        while((temp < vec[j]) && (j >= first))
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1]= temp;
    }
}

// Quick sort implementation
void QuickSort(vector<int> & vec, int first, int last)
{
    if(last - first < 5)
    {
        InsertionSort(vec, first, last);
        return;
    }

    int mid = (first + last) / 2;
    
    if (vec[first]> vec[last])
    {
        swap(vec[first], vec[last]);
    }
    if(vec[mid]> vec[last])
    {
        swap(vec[mid], vec[last]);
    }
    if(vec[first] > vec[mid])
    {
        swap(vec[first], vec[mid]);
    }

    int pivot = vec[mid];
    swap(vec[mid], vec[last -1]);
    int left = first + 1;
    int right = last - 2;

    bool done = false;
    while(!done)
    {
        while(vec[left] < pivot)
        {
            left++;
        }
        while(vec[right] > pivot)
        {
            right--;
        }
        if (right > left)
        {
            swap(vec[left], vec[right]);
            left++;
            right--;
        }
        else
        {
            done=true;
        }

    }
    swap(vec[last - 1], vec[left]);
    QuickSort(vec, first, left -1);
    QuickSort(vec, left +1, last);

}

// Iterative merge sort
void IterativeMergeSort(vector<int> &vec, int first, int last)
{
    int i, j;
    int front, mid, rear;

    for (i = 2; i <= last + 1; i *= 2)
    {
        for (j = 0; j < last + 1; j += i)
        {
            front = j;
            rear = min(j + i - 1, last);
            mid = (front + rear) / 2;
            Merge(vec, front, mid, rear);
        }
    }

    if ((last + 1) % (i / 2) != 0)
    {
        mid = last - (last + 1) % (i / 2);
        Merge(vec, 0, mid, last);
    }
}

// Bubble sort implementation
void BubbleSort(vector<int> &vec, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        for (int j = first; j < last - i + first; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Shell sort implementation
void ShellSort(vector<int> &vec, int first, int last)
{
    // Shell sort algorithm
    int size = last - first + 1;
    for (int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2))
    {
        for (int i = gap; i <= last; i += 1)
        {
            int temp = vec[i];
            int j = i;
            for (; (j >= gap) && (temp < vec[j - gap]); j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}
         
#endif