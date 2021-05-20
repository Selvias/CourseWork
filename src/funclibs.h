#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int *source, int low, int high);
void merge(int *src, int low, int high);
void shellsort(int *src, int size);

int findsize(const char *filename);

void filltxt(int n, const char *filename);
void fillarr(int n, const char *filename, int *tofill);
int writefile(int n, const char *filename, int **towrite);

int command(const char *input, const char *output, const char *type);

int scannum();

int checkrez(int n, int *sorted);