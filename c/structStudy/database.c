#include "database.h"

int hundole_command(int command) {
    static Database db = {0};
    switch (command) {
        case 1:
            add_user(&db);
            break;
        case 2:
            delete_user(&db);
            break;
        case 3:
            search_user(&db);
            break;
        case 4:
            print_user_list(&db);
            break;
        case 5:
            print_user(&db);
            break;
        default:
            printf("不正なコマンドです．");
    }
}

Database* add_user(Database* db) {

}

Database* delete_user(Database* db) {

}

Database* search_user(Database* db) {

}

void print_user_list(const Database* db){

}

void print_user(const Database* db) {
    
}

