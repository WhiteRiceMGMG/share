#include "database.h"

int hundole_command(int command) {
    Database *db
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