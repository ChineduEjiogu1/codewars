#include <stddef.h>
​
/* Do not allocate any memory but just use rdata and return it back */
​
unsigned char *data_reverse(unsigned char *rdata, const unsigned char *data, size_t nblk)
{
    const int chunk_size = 8;
​
    for (size_t start_chunk = 0; start_chunk < nblk; start_chunk++)
    {
        size_t end_chunk = nblk - 1 - start_chunk;
        size_t start_offset = start_chunk * chunk_size;
        size_t end_offset = end_chunk * chunk_size;
​
        for (int bit = 0; bit < chunk_size; bit++)
            rdata[start_offset + bit] = data[end_offset + bit];
    }
​
    return rdata;
}