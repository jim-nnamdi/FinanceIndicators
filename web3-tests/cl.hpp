#pragma once
#ifndef CL_H
#define CL_H

#include <iostream>
#include <cstring>
#include <string>

namespace cx {
    class Cl{
    public:
     struct MemoryStruct {
        char * memory;
        size_t size;
    };
    
    static size_t post_callback(void *ptr, size_t size, size_t nmemb, void *userp);
    };
}
#endif