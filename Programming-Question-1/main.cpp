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

using namespace std;

//#define INPUT_FILE_NAME "IntegerArray.txt"
//#define DATA_SIZE 100001
#define INPUT_FILE_NAME "test1.txt"
#define DATA_SIZE 5
#define STR_SIZE 10

int data_[DATA_SIZE];
unsigned int inversion_;

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

/** swap the data of two address */
void swap(int * left, int * right);

int main()
{
    // procedure 1:  file IO process 
    unsigned int i=0,j=0;
    char   data_char[STR_SIZE];
    ifstream fin(INPUT_FILE_NAME);
    while (fin >> data_char)
    {
        i++;
        data_[i] = atoi(data_char); 
        cout << " Read from array: data["<< i << "]=" << data_[i] << endl;
    }

    // procedure 2: sorted and compute Inversion
    inversion_ = BubbleSort(data_, DATA_SIZE);
             
    // procedure 3: show the result of array and inversion
    i=0;
    while (i < DATA_SIZE)
    {
        i++;
        cout << " Sorted data[" << i << "]=" << data_[i] << endl;
    }

    cout << "Inversion is " << inversion_ << endl;

    return 0;
}


/************************************************************************/
void ReadDataByLineIntoCharArray(ifstream fin, char * data){}
/************************************************************************/
void ReadDataByLineIntoCharArray(fstream fin, char * data){}
/************************************************************************/
void ReadDataByLineIntoSring(ifstream fin, string * data){}
/************************************************************************/
void ReadDataByLineIntoSring(fstream fin, string * data){}
/************************************************************************/
int BubbleSort(int * data, int size)
{
    int invers = 0,i, j = 1;

    while (j < size)
    {
        i = j;
        while (i < size)
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
/************************************************************************/
void swap(int * left, int * right)
{
    int tmp;
    
    tmp = *left;
    *left = *right;
    *right = tmp; 
}
/************************************************************************/
