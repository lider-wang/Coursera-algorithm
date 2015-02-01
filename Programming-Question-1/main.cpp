/**************************************************************************
 **  Standford University Online Course     -   from Coursera
 **         Algorithm: Design and Analysis, Week1 ProblemSet 
 **  This project is design for compute the number of Inversion 
 **  by the unsored data which get from InversionArray.txt
 **  
 **  @file      main.cpp
 **  @author    Lider
 **  Copyright(c) 2015                           2015 Jan. 23
 *************************************************************************/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#define INPUT_FILE_NAME "IntegerArray.txt"
//#define INPUT_FILE_NAME "test1.txt"
#define MAX_DATA_SIZE 100000
#define STR_SIZE 10

#define BUBBLESORT      0x01
#define MERGESORT       0x02
#define INSERTIONSORT   0x04

#define TIME_EXECUTE


/** Read input file stream line-by-line from char array into char array */
void ReadDataByLineIntoCharArray(ifstream fin, char * data);

/** Read file stream line-by-line from string into char array */
void ReadDataByLineIntoCharArray(fstream fin, char * data);

/** Read input file stream line-by-line from char array into char array */
void ReadDataByLineIntoSring(ifstream fin, string * data);

/** Read file stream line-by-line from string into char array */
void ReadDataByLineIntoSring(fstream fin, string * data);

/** Bubble sort */
int BubbleSort(int * data, int size);

/**
 * This function use devide-and-conquer Merge Sort(Resursive method) 
 * to compute inversion number. 
 * @note INVERSION : LEFT_INVERSION + RIGHT_INVERSION + SPLIT_INVERSION
 * @param int*  data array to sort
 * @param int   data array length
 * @return int  Inversion of array
 */
int MergeSort(int * data, int size);

/** Merge procedure */
int Merge(int * dataLeft,int * dataRight, int sizeLeft, int sizeRight);

/** swap the data of two address */
void swap(int * left, int * right);

/** start of execution time calculate */
void StartOfExecuteTime(clock_t* begin);

/** end of execution time calculate */
void EndOfExecuteTime(clock_t* end);

/** calculate the execution time (for second) */
double ExecuteTimeCount(clock_t start, clock_t end);

//-----------------------------------------------------------------------
int main()
{
    // program result 
    unsigned int inversion_;
    int data_[MAX_DATA_SIZE+1];
    int data_size = 0;

    // local variable
    unsigned int i=0;
    char   data_char[STR_SIZE];

    // user define
    static const unsigned char sort_type = MERGESORT;
#ifdef TIME_EXECUTE
    clock_t begin,end;
    StartOfExecuteTime(&begin);
#endif
    
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

    /** procedure 2: sorted and compute Inversion */
    switch(sort_type)
    {
        case BUBBLESORT:
            inversion_ = BubbleSort(data_, data_size);
            break;
        case MERGESORT:
            inversion_ = MergeSort(data_+1, data_size);
            break;
        default:
            break;
    }
             
    /** procedure 3: show the result of array and inversion */
    i = 0;
    while (i < data_size)
    {
        i++;
        cout << " Sorted data[" << i << "]=" << data_[i] << endl;
    }
    cout << "Inversion is " << inversion_ << endl;

#ifdef TIME_EXECUTE
    EndOfExecuteTime(&end);
    cout << "Execution time : " << ExecuteTimeCount(begin, end) << endl;
#endif

    return 0;
}
//-----------------------------------------------------------------------
void ReadDataByLineIntoCharArray(ifstream fin, char * data){}
//-----------------------------------------------------------------------
void ReadDataByLineIntoCharArray(fstream fin, char * data){}
//-----------------------------------------------------------------------
void ReadDataByLineIntoSring(ifstream fin, string * data){}
//-----------------------------------------------------------------------
void ReadDataByLineIntoSring(fstream fin, string * data){}
//-----------------------------------------------------------------------
int MergeSort(int * data, int size)
{
    int invers = 0;
    
    // if size=1, no need to sort
    if (size <= 1)
        return invers;
    
    // check the data size for devide-conquer 
    int mid = size / 2;
    int x = MergeSort(data, mid);
    int y = MergeSort(data + mid, mid + (size % 2));
    int z = Merge(data, data + mid, mid, mid + (size % 2));
    
    invers = x + y + z;
    return invers;
}
//-----------------------------------------------------------------------
int Merge(int * dataLeft,int * dataRight, int sizeLeft, int sizeRight)
{
    // i : dataLeft flag
    // j : dataRight flag
    // k : mergeStorge flag
    // invers : invertion of this procedure 
    int invers = 0, i = 0, j = 0, k = 0; 
    int mergeStorge[(sizeLeft + sizeRight)]; 
   
    for (k = 0; k < (sizeLeft + sizeRight); k++)
    {
        // check if one part of data is empty
        if (i >= sizeLeft)
            mergeStorge[k] = dataRight[j++]; 
        else if (j >= sizeRight)
            mergeStorge[k] = dataLeft[i++];
        // check which one is smaller
        else if (dataLeft[i] < dataRight[j])
            mergeStorge[k] = dataLeft[i++];
        else
        {
            mergeStorge[k] = dataRight[j++];
            invers += (sizeLeft - i);
        }
    }
    
     
    // copy mergeStorge result into dataLeft and dataRight 
    memcpy(dataLeft, mergeStorge, sizeof(int)*(sizeLeft + sizeRight));

    return invers;
}
//-----------------------------------------------------------------------
int BubbleSort(int * data, int size)
{
    int invers = 0;
    int i = 1;
    int j = 1;

    while (j < size)
    {
        i = 1;
        while (i <= (size - j))
            {
                if (data[i] > data[i+1])
                {
                    swap(&data[i], &data[i+1]);
                    invers++;
                }
                i++;
            }
        j++;
    } 
    
    return invers;
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
void StartOfExecuteTime(clock_t* begin)
{
    *begin = clock();
}

//-----------------------------------------------------------------------
void EndOfExecuteTime(clock_t* end)
{
    *end = clock();
}
//-----------------------------------------------------------------------
double ExecuteTimeCount(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}
