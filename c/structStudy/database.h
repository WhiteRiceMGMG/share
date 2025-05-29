#ifndef DATABASE_H
#define DATABASE_H

#define ARRAY_MAX 63
#define NAME_MAX 23
#define BORN_MAX 23
#define JOB_MAX 23

typedef struct {
    int userId[ARRAY_MAX+ 1];
    char userName[ARRAY_MAX + 1][NAME_MAX + 1];
    char userJob[ARRAY_MAX + 1][JOB_MAX];
    char userBorn[ARRAY_MAX + 1][NAME_MAX + 1];
    int userAge[ARRAY_MAX + 1];
} Database;

int hundole_command(int command);

Database* add_user(Database* db);

Database* delete_user(Database* db);

Database* search_user(Database* db);

void print_user_list(const Database* db)

void print_user(const Database* db)

