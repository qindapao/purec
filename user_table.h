// user_table.h
#ifndef USER_TABLE_H
#define USER_TABLE_H

#include "uthash.h"

// 避免使用容易冲突的名字，如 hh/next/prev，统一加前缀
typedef struct user_entry {
    int id;                     // key
    char name[64];
    UT_hash_handle uhh;        // 使用独特名字 uhh，防止误冲突
} user_entry;

// 哈希表操作接口
void user_table_add(user_entry **table, int id, const char *name);
user_entry* user_table_find(user_entry *table, int id);
void user_table_delete(user_entry **table, int id);
void user_table_free(user_entry **table);

#endif // USER_TABLE_H
