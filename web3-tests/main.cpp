#include<stdio.h>
#include<stdlib.h>
#include "cl.hpp"

using namespace std;
using namespace cx;

size_t cx::Cl::post_callback(void *contents, size_t size, size_t nobj, void *userp) {
    size_t realsize = size * nobj;
    struct MemoryStruct *memx = (struct MemoryStruct *)userp;
    char * ptr = (char *)realloc(memx->memory, memx->size + realsize + 1);
    if(!ptr) cerr << "realloc failed" << endl; return 0; 

    memx->memory =  ptr;
    memcpy(&(memx->memory[memx->size]),contents,realsize);
    memx->size += realsize;
    memx->memory[memx->size] = 0;
    return realsize;
}

struct mex {
    char * mem;
    int size;
};

size_t writecallback(void *contents, size_t size, size_t nmemb, void *userptr) {
    size_t realsize = size * nmemb;
    struct mex *memx = (struct mex *)userptr;
    char * ptr = (char *) realloc(memx->mem, memx->size + realsize + 1);
    if(!ptr) cerr << "realloc failed" << endl; return 0;

    memx->mem = ptr;
    memcpy(&(memx->mem[memx->size]), contents, realsize);
    memx->size = realsize;
    memx->mem[memx->size] = 0;
    return realsize;
}