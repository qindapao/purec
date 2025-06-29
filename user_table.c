// user_table.c
#include <stdlib.h>
#include <string.h>
#include "user_table.h"

void user_table_add(user_entry **table, int id, const char *name) {
    user_entry *s = NULL;
    HASH_FIND_INT(*table, &id, s);
    if (!s) {
        s = malloc(sizeof(user_entry));
        s->id = id;
        strncpy(s->name, name, sizeof(s->name) - 1);
        s->name[sizeof(s->name) - 1] = '\0';
        HASH_ADD_INT(*table, id, s);
    }
}

user_entry* user_table_find(user_entry *table, int id) {
    user_entry *s = NULL;
    HASH_FIND_INT(table, &id, s);
    return s;
}

void user_table_delete(user_entry **table, int id) {
    user_entry *s = NULL;
    HASH_FIND_INT(*table, &id, s);
    if (s) {
        HASH_DEL(*table, s);
        free(s);
    }
}

void user_table_free(user_entry **table) {
    user_entry *curr, *tmp;
    HASH_ITER(uhh, *table, curr, tmp) {
        HASH_DEL(*table, curr);
        free(curr);
    }
}
