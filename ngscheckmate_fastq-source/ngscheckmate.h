#ifndef NGSCHECKMATE_H
#define NGSCHECKMATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include "stringhash2.h"
#define FILENAMEMAX 1000
#define SINGLE_LINE_MAX 1000

typedef struct read_fastq_args_struct
{
   char* fastqfilename;
   char* fastqfilename2;
   hash* h;
   long** count_array;
   int patternlength;
   double subsampling_rate;
   long startpos;
   long endpos;
} read_fastq_args;





extern int nthread;
extern pthread_t *pth;
extern int *working_thread;

extern int max_index;
extern int read_length;
extern long nReads;
extern char nodeptherror;
extern char* index_array;

hash* read_patternfile_construct_hash(char*);
void store_each_pattern (char*, char, int, hash*);
long*** build_count_array(void);
void* read_fastq_thread(void*);
void read_fastq (char*, hash*, long**, int, double, long, long);
void read_fastq_PE (char*, char*, hash*, long**, int, double, long, long);
void print_count_array(long***,char*);
void create_index_array(char*);

double guess_subsampling_rate (double, double, char);
void get_readlength_nReads (char*);

#endif

