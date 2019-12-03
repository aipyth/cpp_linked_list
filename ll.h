#include <cstddef>
#include <ostream>
#include <fstream>

namespace LL {
    typedef char TE [10];

    struct LE {
        TE data;
        LE* next;
    };


    LE* create(const char data[] = "");
    void delete_LL(LE* start);
    unsigned int size(LE* element);
    LE* index(LE* list, long index);
    void push_back(LE* list, const char data[] = {});
    void ll_to_stream(LE* list, std::ostream &out, const char delimiter = '\n');
    void ll_to_file(LE* list, const char* filename);
    LE* ll_from_stream(std::istream &in, bool empty_lines = true);
    LE* ll_from_file(const char* filename);
    unsigned int count_same_begin_n_end(LE* list);
    unsigned int count_same_begin(LE* list);
    int compare(char* str1, char* str2);
    unsigned int count_equals_last(LE* list);
}