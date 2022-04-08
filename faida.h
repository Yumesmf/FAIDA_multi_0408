#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <thread>

#include <sstream>
#include <typeinfo>

#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <algorithm>
#include <bitset>
#include <time.h>
#include <pthread.h>

using namespace std;

#define LINE_BUF_SIZE 512
#define NUM_THREADS 4

char *word;
char *tmp;

struct Record
{
    vector<string> cell;
};

struct CSVDATA
{
    list<Record> data;
    char *name;
};

CSVDATA csvData_1, csvData_1_hash;
CSVDATA csvData_2, csvData_2_hash;
list<string> hash_hll_1;
list<string> hash_hll_2;
vector<int> record;

// prototype
pair<CSVDATA, CSVDATA>
get_record_col_count(const char *path, CSVDATA csvdata, CSVDATA csvdata_hash);
pair<CSVDATA, CSVDATA> insert_structure(CSVDATA csvdata, CSVDATA csvdata_hash, int record_count, int col_count, FILE *fp, const char *path);
void print_csv(CSVDATA csvdata);
string StrToBitStr(string str);
//
