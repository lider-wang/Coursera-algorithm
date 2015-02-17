/**************************************************************************
 **  Standford University Online Course     -   from Coursera
 **         Algorithm: Design and Analysis, Week2 ProblemSet 
 **
 **  Features of Quick Sort
 **     - linear O(n) time, no extra memory
 **     - reduce problem size
 **  
 **  @file      main.cpp
 **  @author    Lider
 **  Copyright(c) 2015                           2015 Feb. 6
 *************************************************************************/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#define INPUT_FILE_NAME "QuickSort.txt"
//#define INPUT_FILE_NAME "test1.txt"
#define MAX_DATA_SIZE   100000
#define STR_SIZE        10
#define QUICKSORT       0x01

#define PIVOT_FIRST         0x01
#define PIVOT_LAST          0x02
#define PIVOT_MEDIAN_OF_THREE  0x03
#define PIVOT_APPORCH       PIVOT_MEDIAN_OF_THREE

#define TIME_EXECUTE

/**
 * This function use devide-and-conquer Quick Sort strategy
 * to sort and  compute the number of comparisons 
 * @note    the procedures are exactly the same of class describe
 * @param   int* data array start (position 0 of array)
 * @param   int* data array end
 * @return  int  number of comparisons
 */
int QuickSort(int * dataStart, int * dataEnd);

/**
 * This function divide the data array into two sub-routine by chosen pivot
 * which call by QuickSort recursively.
 * 
 * @param   int*    data array start
 * @param   int*    data array end
 * @param   int     pivot index
 * @return  int     pivot index after partition
 */
int Partition(int * dataStart, int * dataEnd, int p);

/** return pivot index */
int choosePivot(int * dataStart, int * dataEnd);

/** swap the data of two address */
void swap(int * left, int * right);

/** start of execution time calculate */
void StartOfExecuteTime(clock_t* begin);

/** end of execution time calculate */
void EndOfExecuteTime(clock_t* end);

/** calculate the execution time (for second) */
double ExecuteTimeCount(clock_t start, clock_t end);

int main(int argc, char** argv)
{

#ifdef TIME_EXECUTE
    clock_t begin,end;
    StartOfExecuteTime(&begin);
#endif

    // program result variable
    unsigned int comparison;
    int data_[MAX_DATA_SIZE + 1];
    int data_size = 0;

    // local variable
    unsigned int i = 0;
    char data_char[STR_SIZE];


    /**  procedure 1:  file IO process */
    ifstream fin;
    fin.open(INPUT_FILE_NAME,ios::in);
    while (fin >> data_char)
    {
        i++;
        data_[i] = atoi(data_char); 
        cout << " Read from array: data["<< i << "]=" << data_[i] << endl;
    }

    cout << "Total " << i << " element" << endl;
    data_size = i;
    data_[0]  = -1;

    /** procedure 2: sorted and compute comparison */
    comparison = QuickSort(data_, data_ + i);


    //-----------------------
    for (i=0; i <= data_size; i++)
        cout << "MAIN INFO: data array [" << i << "]:" << data_[i] << endl;
    cout << "MAIN INFO: comarison is " << comparison << endl;
    //-----------------------
#ifdef TIME_EXECUTE
    EndOfExecuteTime(&end);
    cout << "Execution time : " << ExecuteTimeCount(begin, end) << endl;
#endif


    return 0;
}

//-----------------------------------------------------------------------
int choosePivot(int * dataStart, int * dataEnd)
{
    unsigned int size   = dataEnd - dataStart;
    unsigned int first  = *(dataStart + 1);
    unsigned int last   = *(dataEnd);
    unsigned int middle = *(dataStart + (unsigned int) (size+1)/2);
    
    switch (PIVOT_APPORCH)
    {
        case PIVOT_FIRST:
            return 1;
        case PIVOT_LAST:
            return size;
        case PIVOT_MEDIAN_OF_THREE:
            if ((first > last) && (first > middle))
            { 
                if (middle > last)
                    return (int) (size+1)/2;
                else
                    return size;
            } else if ((middle > last) && (middle > first))
            {
                if (first > last)
                    return 1;
                else
                    return size;
            } else 
            {
                if (first > middle)
                    return 1;
                else
                    return (int) (size+1)/2;
            }
            break;
    default:
        return 1;        
    }
}
//-----------------------------------------------------------------------
int Partition(int * dataStart, int * dataEnd, int p)
{
    int i = 2, j = 2;
    unsigned int size = dataEnd - dataStart;
    unsigned int pivot = *(dataStart + p);
    
    // check i and j is not equal to p
    if (p != 1)
        swap(dataStart + 1, dataStart + p);

    // travers and partition
    while (j <= size)
    {
    //-----------------------
        cout << "PARTITION INFO: i,j:" << i << "," << j << endl; 
    //-----------------------
        if ( *(dataStart + j) < pivot )
        {
            swap(dataStart + j, dataStart + i);
            i++;
            cout << "PARTITION INFO: swap!!" << endl;

        }
        j++;
    }

    // swap pivot to correct position
    swap(dataStart + 1, dataStart + i - 1);

    return (i - 1);
}
//-----------------------------------------------------------------------
int QuickSort(int * dataStart,int * dataEnd)
{
    int size = dataEnd - dataStart;
    int comparison = 0;
    unsigned int  pivotIndexBefore;
    unsigned int  pivotIndexAfter;
   
    //-----------------------
    for (int i=0; i <= size; i++)
        cout << "QUICKSORT INFO: 1.data array [" << i << "]:" << dataStart[i] << endl;
    //-----------------------
    
    if (size < 2)
    {
        cout << "break;" << endl;
        return 0;
    }
    // choose pivot    
    pivotIndexBefore = choosePivot(dataStart, dataEnd);

    //-----------------------
        cout << "QUICKSORT INFO: pivot Index Before:" << pivotIndexBefore << " value:"<< *(dataStart+pivotIndexBefore) << endl;
    //-----------------------
    
    // Partition sub-routine
    pivotIndexAfter = Partition(dataStart, dataEnd, pivotIndexBefore);
    comparison = size - 1;

    //-----------------------
        cout << "QUICKSORT INFO: pivot Index After:" << pivotIndexAfter << endl;
    for (int i=0; i <= size; i++)
        cout << "QUICKSORT INFO: 2.data array [" << i << "]:" << dataStart[i] << endl;
    //-----------------------
    // devide-and-conquer subroutines and calculate the comparison
    comparison += QuickSort(dataStart, dataStart + pivotIndexAfter - 1);
    comparison += QuickSort(dataStart + pivotIndexAfter, dataEnd);

    // return comparison
    return comparison;
}
//-----------------------------------------------------------------------
void swap(int * left, int * right)
{
    int tmp;
    
    tmp = *left;
    *left = *right;
    *right = tmp; 
}
//-----------------------------------------------------------------------
void StartOfExecuteTime(clock_t * begin)
{
    *begin = clock();
}

//-----------------------------------------------------------------------
void EndOfExecuteTime(clock_t * end)
{
    *end = clock();
}
//-----------------------------------------------------------------------
double ExecuteTimeCount(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}


