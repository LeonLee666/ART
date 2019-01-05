//
// Created by bombehub on 2019/1/5.
//

#include <stdio.h>
#include "art.h"
#include <string.h>
int main(int argc, char **argv) {
    art_tree t;
    int res = art_tree_init(&t);

    int len;
    char buf[512];
    FILE *f = fopen("../dataset/words.txt", "r");

    uintptr_t line = 1;
    while (fgets(buf, sizeof buf, f)) {
        len = strlen(buf);
        buf[len - 1] = '\0';
        art_insert(&t, (unsigned char *) buf, len, (void *) line);
        //printf("%lld\n",art_size(&t) );
        line++;
    }


    fseek(f, 0, SEEK_SET);
    // Search for each line
    line = 1;
    while (fgets(buf, sizeof buf, f)) {
        len = strlen(buf);
        buf[len-1] = '\0';

        uintptr_t val = (uintptr_t)art_search(&t, (unsigned char*)buf, len);
        printf("Line: %ld Val: %ld Str: %s\n", line,val, buf);
        line++;
    }


    res = art_tree_destroy(&t);

}
