#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_USERS 100
#define ID_LEN 15
#define NAME_LEN 50
#define NUM_LEN 15
#define GEN_LEN 10
#define EMA_LEN 50
#define DEP_LEN 50
#define PASS_LEN 50


//구조체 
typedef struct {
    char id[ID_LEN];
    char name[NAME_LEN];
    char num[NUM_LEN];
    char gen[GEN_LEN];
    char ema[EMA_LEN];
    char dep[DEP_LEN];
    char pass[PASS_LEN];
} user;



//이메일 문자 찾는 함수
int contains_char(const char* str, char ch) {

    return strchr(str, ch) != NULL;

}

user users[MAX_USERS];
int users_count = 0;
int su = 0;
char id2[ID_LEN], pass2[PASS_LEN];

//회원가입
void signup() {
    if (users_count >= MAX_USERS) {
        printf("더 이상 회원가입을 할 수 없습니다\n");
        return;
    }

    //아이디
    printf("학번(=아이디)를 입력하시오 (예시 : 22411888)\n");
    scanf("%14s", users[users_count].id);

    int id_len = strlen(users[users_count].id);

    if (id_len == 8) {

        for (int i = 0; i < 9; i++) {

            if (isdigit(users[users_count].id)) {

            }

            else {
                printf("숫자로만 입력해주세요\n");
                return;
            }
        }
    }
    else {
        printf("학번는 8자리로 입력해주십시오 \n");
        return;
    }


    //이름
    printf("이름을 입력하시오\n");
    scanf("%49s", users[users_count].name);

    if (isalpha(users[users_count].name) == 0) {
        printf("올바르지 않은 형식입니다");
        return;
    }


    //전화번호
    printf("전화번호를 입력하시오 (- 제외)\n");
    scanf("%14s", users[users_count].num);

    int num_len = strlen(users[users_count].num);

    if (num_len == 11) {

        for (int i = 0; i < 12; i++) {

            if (isdigit(users[users_count].num)) {

            }

            else {
                printf("숫자로만 입력해주세요\n");
                return;
            }
        }
    }
    else {
        printf("전화번호는 11자리로 입력해주십시오 \n");
        return;
    }





    //성별
    printf("성별을 입력하시오(남/여) \n");
    scanf("%9s", users[users_count].gen);

    if (strcmp(users[users_count].gen, "남") != 0 && strcmp(users[users_count].gen, "여") != 0) {

        printf("오류로 인해 종료되었습니다\n");
        return;
    }


    //이메일 
    printf("이메일을 입력하시오 \n");
    scanf("%49s", users[users_count].ema);


    if (contains_char(users[users_count].ema, '@') && contains_char(users[users_count].ema, '.')) {

        if (strstr(users[users_count].ema, ".com") == NULL) {
            printf("유효하지 않는 이메일입니다\n");
        }
    }
    else {
        printf("유효하지 않은 이메일입니다\n");
        return;
    }


 
    //학과
    printf("학과를 입력하시오 \n");
    scanf("%49s", users[users_count].dep);



    //비밀번호
    printf("비밀번호를 입력하시오 \n");
    scanf("%49s", users[users_count].pass);

    users_count++; // 사용자 수 증가
}


//로그인
void login() {
    while (1) {
        printf("로그인을 시작하겠습니다\n\n");
        printf("-1 입력시 로그인 종료\n");
        printf("아이디(=학번)를 입력하시오\n");
        scanf("%14s", id2);

        if (strcmp(id2, "-1") == 0) {
            return;
        }

        printf("비밀번호를 입력하시오\n");
        scanf("%49s", pass2);

        for (int i = 0; i < users_count; i++) {
            if (strcmp(id2, users[i].id) == 0 && strcmp(pass2, users[i].pass) == 0) {
                printf("로그인 되었습니다\n");
                su = 1; // 로그인 상태를 1로 설정
                return;
            }
        }
        printf("아이디 혹은 비밀번호가 잘못 입력되었습니다.\n");
    }
}


//로그아웃
void logout() {
    if (su == 1) {
        printf("로그아웃 되었습니다\n");
        su = 0;
    }
    else {
        printf("로그인을 하지 않았습니다\n");
    }
}


//마이페이지
void mypage() {
    if (su == 1) {
        printf("\n마이페이지 조회!\n");
        for (int i = 0; i < users_count; i++) {
            if (strcmp(users[i].id, id2) == 0) {
                printf("학번: %s\n", users[i].id);
                printf("이름: %s\n", users[i].name);
                printf("전화번호: %s\n", users[i].num);
                printf("성별: %s\n", users[i].gen);
                printf("이메일: %s\n", users[i].ema);
                printf("학과: %s\n", users[i].dep);
                printf("비밀번호는 보안상 비밀 ~~!! \n");
                return;
            }
        }
    }
    else {
        printf("로그인을 하지 않았습니다.\n");
    }
}


//메인화면
int main() {
    int a;

    while (1) {
        printf("\n무엇을 하시겠습니까?\n");
        printf("로그인(0을 입력), 로그아웃(1을 입력), 마이페이지 조회(2를 입력), 회원가입(3을 입력), 종료(-1을 입력)\n");
        scanf("%d", &a);

        if (a == -1) {
            printf("프로그램이 종료되었습니다.");
            return 0;
        }
        else if (a == 0) {
            login();
        }
        else if (a == 1) {
            logout();
        }
        else if (a == 2) {
            mypage();
        }
        else if (a == 3) {
            signup();
        }
        else {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
