#include "ll.h"

using namespace LL;

int str_size(char* str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}


LL::LE* LL::create(const char *data) {
    LE* element = new LE;

    for (int i = 0; (data[i] != '\0') && (i < 10); i++) {
        element->data[i] = data[i];
    }
    
    element->next = NULL;

    return element;
}

void LL::delete_LL(LE* start) {
    LE* current = start;
    LE* next;
    do {
        next = current->next;
        delete current;
        current = next;
    } while (current);
}

unsigned int LL::size(LL::LE* element) {
    LE* current = element;
    unsigned int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

LL::LE* LL::index(LE* list, long index) {
    LE* current = list;
    unsigned int counter = 0;
    unsigned int size = LL::size(list);
    if (index < 0) {
        size = size + index;
        while ((current->next != NULL) && (counter != size)) {
            current = current->next;
            counter++;
        }
    } else {
        for (unsigned int i = 0; (i != index) && (current->next != NULL) && (i != size); i++) {
            current = current->next;
        }
    }
    return current;
}

void LL::push_back(LE* list, const char *data) {
    LE* current = list;
    LE* new_element = LL::create(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_element;
}

void LL::ll_to_stream(LL::LE* list, std::ostream &out, const char delimiter) {
    LE* current = list;
    do {
        out.write(current->data, str_size(current->data));
        out.put(delimiter);
        current = current->next;
    } while (current != NULL);
    if (delimiter != '\n')
        out.put('\n');
}

void LL::ll_to_file(LL::LE* list, const char* filename) {
    std::ofstream out (filename);
    LL::ll_to_stream(list, out);
    out.close();
}

LL::LE* LL::ll_from_stream(std::istream &in, bool empty_lines) {
    LE* list = create();
    if (in.good()) {
        LL::TE c;
        in.getline(list->data, 10);

        while (in.good()) {
            in.getline(c, 10);
            if ((c[0] == '\0') && (!empty_lines))
                break;
            LL::push_back(list, c);
        }
    }
    return list;
}

LL::LE* LL::ll_from_file(const char* filename) {
    std::ifstream in (filename);
    LE* list = LL::ll_from_stream(in);
    in.close();
    return list;
}

unsigned int LL::count_same_begin_n_end(LL::LE* list) {
    unsigned int counter = 0;
    char begin, end;
    LE* current = list;
    while (current != NULL) {
        begin = current->data[0];
        for (int i = 0; (current->data[i] != '\0'); i++) {
            end = current->data[i];
        }

        if (begin == end) {
            counter++;
        }

        current = current->next;
    }
    return counter;
}

unsigned int LL::count_same_begin(LL::LE* list) {
    unsigned int counter = 0;
    LE* current = list;
    while (current->next != NULL) {
        if (current->data[0] == current->next->data[0]) {
            counter++;
        }

        current = current->next;
    }
    return counter;
}

int LL::compare(char* str1, char* str2) {
    unsigned int len_str1 = str_size(str1), len_str2 = str_size(str2);
    if (len_str1 != len_str2) {
        return -1;
    }

    for (int i = 0; i < len_str1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

unsigned int LL::count_equals_last(LL::LE* list) {

    unsigned int counter = 0;
    int i = 0;
    LE* current = list;

    char* last_elem_data = index(list, -1)->data;
    while (current->next != NULL) {        
        if ( compare(current->data, index(list, -1)->data) == 1 ) {
            counter++;
        }
        current = current->next;
        i++;
    }

    return counter;
}


