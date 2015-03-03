/**************************************************************************
 **  Standford University Online Course     -   from Coursera
 **         Algorithm: Design and Analysis, Week3 ProblemSet 
 **
 **  Features of Karger's algorithm (random contraction algorithm)
 **     - 
 **     - reduce problem size
 **  
 **  @file      main.cpp
 **  @author    Lider
 **  Copyright(c) 2015                           2015 Feb. 17
 *************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#define INPUT_FILE_NAME "kargerMinCut.txt"
#define STR_SIZE        100
#define GRAPH_SIZE      200

#define GRAPH_TYPE_ADJLIST      0x01
#define GRAPH_TYPE_ADJMATRIX    0x02
#define GRAPH_TYPE_DEFULT       GRAPH_TYPE_ADJLIST

#define TIME_EXECUTE
#define NEW_NODE (struct node*)malloc(sizeof(struct node))

typedef struct node 
{
    int index;
    struct node* next;
}Node;

typedef struct edge
{
    int weight;
    int vertex[2];
}Edge;

/** construct the node adj-list(in order) from input file */
void adj_node_insert(Node* adj_list, int index);

/** create and allocate the graph */
Node* graph_init(int size);

/** print and show graph */
void adj_graph_print(Node* graph);

/***/
int min_cut(Node* graph, int size);

/** swap the data of two address */
void swap(int* left, int* right);

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
    string data_str;
    int min_cut  = 0;
    Node* graph = NULL;
    

    // local variable
    int i=0;
    int tmp=0;

    /**  procedure 1:  file IO process and construct graph */
    ifstream fin;
    int base;
    fin.open(INPUT_FILE_NAME,ios::in);
    graph = graph_init(GRAPH_SIZE);
    
    
    while (std::getline(fin, data_str))
    {
        std::istringstream iss(data_str);
        if (! (iss >> base))
            break;
        cout << "base : " << base << endl;
        while (iss >> tmp)
        {
            cout << " -tmp-" << tmp << endl;
            adj_node_insert(&graph[base], tmp);
        }
    }
    
    /** procedure 2: Random Contraction Algorithm and min-cut problem */
    min_cut = min_cut(graph, GRAPH_SIZE);


#ifdef TIME_EXECUTE
    EndOfExecuteTime(&end);
    cout << "Execution time : " << ExecuteTimeCount(begin, end) << endl;
#endif


    return 0;
}

//-----------------------------------------------------------------------
void adj_node_insert(Node* adj_list, int index)
{
    Node* node_new = NEW_NODE;
    node_new->next  = NULL;
    node_new->index = index;

    Node* current   = adj_list;
    Node* backup    = adj_list;
    while (current->next != NULL)
    {   
        // choose location in this loop
        backup  = current->next;
        if (backup == NULL)
            break;
        else if (backup->index > index)
            break;
        
        current = current->next;
    }

    // insert node after current location
    node_new->next = current->next;
    current->next  = node_new;
}
//-----------------------------------------------------------------------
Node* graph_init(int size)
{
    Node* graph = (Node*) malloc(sizeof(Node) * (size+1));
    for(int i=0; i<=size; i++)
    {
        graph[i].index  = i;
        graph[i].next   = NULL;
    }
    return graph;
}
//-----------------------------------------------------------------------
void adj_graph_print(Node* graph)
{
    int i,iend;
    iend = GRAPH_SIZE;

    for ( i=1; i<=iend; i++)
    {
        Node* current = &graph[i];
        cout << "*************************" << endl;
        cout << "Node[" << current->index  << "]: " << endl;
        while (current->next != NULL)
        {
            current = current->next;
            cout << "-" << current->index  << "-";
        }

        cout << endl;
    }
}
//-----------------------------------------------------------------------
int min_cut(Node* graph, int size)
{
    // copy graph;
    
    // random select node
    // contract node
    // delete unused
    
    return 0;
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

