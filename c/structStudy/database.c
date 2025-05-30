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


Database* add_user(Database* db) {
    int index = db->userCount;

    char (*userName)[NAME_MAX + 1] = db->userName;
    printf("INPUT YOUR NAME:\n");
    fgets(db->userName[index],NAME_MAX,stdin);
    //fgets改行文字まで受け取り，これをヌル文字で置き換える．
    db->userName[index][strcpn(db->userName[index],"\n")] = '\0';
    
    char (*userJob)[NAME_MAX + 1] = db->userJob;
    printf("INPUT YOUR JOB:\n");
    fgets(db->userJob[index],NAME_MAX,stdin);
    db->userJob[index][strcpn(db->userJob[index],"\n")] = '\0';
    
    char (*userBorn)[NAME_MAX + 1] = db->userBorn;
    printf("INPUT YOUR BORN:\n");
    fgets(db->userBorn[index],NAME_MAX,stdin);
    db->userBorn[index][strxpn(db->userBorn[index],"\n")] = '\0';

    int (*userAge) = db->userAge;
    printf("INPUT YOUR AGE:\n");
    scanf("%d",userAge);    




    char (*userBorn)[NAME_MAX + 1] = db->userBorn;
    int userAge = db->userAge;


    


}

Database* delete_user(Database* db) {

}

Database* search_user(Database* db) {

}

void print_user_list(const Database* db){

}

void print_user(const Database* db) {
    
}

