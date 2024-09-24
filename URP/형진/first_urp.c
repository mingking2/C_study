#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 회원가입 함수
void sign_up(char sign_up_answer[50][8][50], int* user_count, int* user_index) {
    if (*user_count >= 50) {
        printf("최대 학생 수에 도달해 더 이상 회원가입이 불가능합니다.");
        return;
    }

    int i = *user_count;

    // 학번
re_ID:
    printf("\n학번(아이디)을 입력하세요. (예: 22411987): ");
    scanf("%s", sign_up_answer[i][0]);
    for (int j = 0; j < strlen(sign_up_answer[i][0]); j++) {
        if (!isdigit(sign_up_answer[i][0][j])) {
            printf("학번은 숫자로 입력해야 합니다. 다시 입력해주세요.\n");
            while (getchar() != '\n');
            goto re_ID;
        }
        else if(strlen(sign_up_answer[i][0]) != 8){
            printf("학번은 숫자 8자리로 입력해야 합니다. 다시 입력해주세요.\n");
            while(getchar() != '\n');
            goto re_ID;
        }
    }

    // 이름
re_NAME:
    printf("\n이름을 입력하세요. (예: 홍길동): ");
    scanf("%s", sign_up_answer[i][1]);
    for (int j = 0; j < strlen(sign_up_answer[i][1]); j++) {
        if (ispunct(sign_up_answer[i][1][j]) || isdigit(sign_up_answer[i][1][j])) {
            printf("이름은 한글 또는 영어로 입력해야 합니다. 다시 입력해주세요.\n");
            while (getchar() != '\n');
            goto re_NAME;
        }
    }

    // 전화번호
re_PH:
    printf("\n전화번호를 입력하세요 (예: 01012345678): ");
    scanf("%s", sign_up_answer[i][2]);
    if (strlen(sign_up_answer[i][2]) != 11) {
        printf("전화번호는 11자리여야 합니다. 다시 입력해주세요.\n");
        while (getchar() != '\n');
        goto re_PH;
    }
    else if (strncmp(sign_up_answer[i][2], "010", 3) != 0) {
        printf("전화번호는 010으로 시작해야 합니다. 다시 입력해주세요.\n");
        while (getchar() != '\n');
        goto re_PH;
    }
    for (int j = 0; j < strlen(sign_up_answer[i][2]); j++) {
        if (!isdigit(sign_up_answer[i][2][j])) {
            printf("전화번호는 숫자로만 입력해야 합니다. 다시 입력해주세요.\n");
            while (getchar() != '\n');
            goto re_PH;
        }
    }

    // 성별
re_gender:
    printf("\n성별을 입력하세요. ('남' 또는 '여'로 입력): ");
    scanf("%s", sign_up_answer[i][3]);
    if (strcmp(sign_up_answer[i][3], "남") != 0 && strcmp(sign_up_answer[i][3], "여") != 0) {
        printf("성별은 '남' 또는 '여'로 정확하게 입력해야 합니다. 다시 입력해주세요.\n");
        while (getchar() != '\n');
        goto re_gender;
    }

    // 이메일
    printf("\n이메일을 입력하세요.: ");
    scanf("%s", sign_up_answer[i][4]);

    // 학과
re_DEPARTMENT:
    printf("\n학과(학부)를 입력하세요.: ");
    scanf("%s",sign_up_answer[i][5]);
    while (getchar() != '\n');
    for (int j = 0; j < strlen(sign_up_answer[i][5]); j++) {
        if (ispunct(sign_up_answer[i][5][j]) || isdigit(sign_up_answer[i][5][j])) {
            printf("학과는 한글 또는 영어로 입력해야 합니다. 다시 입력해주세요.\n");
            goto re_DEPARTMENT;
        }
    }

    // 비밀번호
    printf("\n비밀번호를 입력하세요.: ");
    scanf("%s", sign_up_answer[i][6]);

    // 비밀번호 확인
re_PW_CHECK:
    printf("\n비밀번호를 다시 입력하세요.(확인용): ");
    scanf("%s", sign_up_answer[i][7]);
    if (strcmp(sign_up_answer[i][6], sign_up_answer[i][7]) != 0) {
        printf("비밀번호가 같지 않습니다. 다시 입력해주세요.\n");
        goto re_PW_CHECK;
    }

    // 회원가입 완료
    (*user_count)++;
    *user_index = i;
    printf("\n%s님, 회원가입이 성공적으로 완료되었습니다.\n", sign_up_answer[*user_index][1]);
}

// 로그인 함수
void login(char sign_up_answer[50][8][50], int user_count, int* user_index) {
    while (1) {
        char input_ID[50], input_password[50];
        printf("학생종합정보시스템 로그인을 시작합니다. 아래 항목에 알맞게 기입하세요.\n");
        printf("학번을 입력하세요: ");
        scanf("%s", input_ID);
        printf("비밀번호를 입력하세요: ");
        scanf("%s", input_password);

        int login_success = 0;
        for (int i = 0; i < user_count; i++) {
            if (strcmp(input_ID, sign_up_answer[i][0]) == 0 && strcmp(input_password, sign_up_answer[i][6]) == 0) {
                printf("로그인에 성공하였습니다.\n");
                *user_index = i;
                login_success = 1;
                break;
            }
        }
        if (login_success) {
            break;
        }
        else {
            printf("로그인에 실패하였습니다. 다시 시도하십시오.\n");
        }
    }
}

// 마이페이지 조회 함수
void mypage(char sign_up_answer[50][8][50], int user_index) {
    printf("\n%s 학생의 마이페이지를 조회합니다.\n", sign_up_answer[user_index][1]);
    printf("학번(아이디): %s\n", sign_up_answer[user_index][0]);
    printf("이름: %s\n", sign_up_answer[user_index][1]);
    printf("전화번호: %s\n", sign_up_answer[user_index][2]);
    printf("성별: %s\n", sign_up_answer[user_index][3]);
    printf("이메일: %s\n", sign_up_answer[user_index][4]);
    printf("학과(학부): %s\n\n", sign_up_answer[user_index][5]);
}

// 로그아웃 함수
void logout() {
    printf("\n로그아웃 되었습니다.\n");
}

int main() {
    char sign_up_answer[50][8][50];
    int user_count = 0, user_index = 0, sign_up_statue = 0, login_statue = 0, choice;

    while (1) {
        printf("반갑습니다, 학생종합정보시스템입니다.\n");
        printf("1. 회원가입\n2. 로그인\n3. 마이페이지 조회\n4. 로그아웃\n-1.종료\n(잘못 입력할 시 학생종합정보시스템이 비정상적으로 종료됨에 주의하십시오. 숫자로 입력할 것.)\n선택: ");
        scanf("%d", &choice);
        {
            if (choice == 1) {
                sign_up(sign_up_answer, &user_count, &user_index);
                sign_up_statue = 1;
            }
            else if (choice == 2) {
                if (!sign_up_statue) {
                    printf("회원가입 내역이 존재하지 않습니다. 회원가입을 먼저 진행해주세요.\n\n");
                }
                else {
                    login(sign_up_answer, user_count, &user_index);
                    login_statue = 1;
                }
            }
            else if (choice == 3) {
                if (!sign_up_statue) {
                    printf("회원가입 내역이 존재하지 않습니다. 회원가입을 먼저 진행해주세요.\n\n");
                }
                else if (!login_statue) {
                    printf("로그인 내역이 존재하지 않습니다. 로그인을 먼저 진행해주세요.\n\n");
                }
                else {
                    mypage(sign_up_answer, user_index);
                }
            }
            else if (choice == 4) {
                if (!sign_up_statue) {
                    printf("회원가입 내역이 존재하지 않습니다. 회원가입을 먼저 진행해주세요.\n\n");
                }
                else if (!login_statue) {
                    printf("로그인 내역이 존재하지 않습니다. 로그인을 먼저 진행해주세요.\n\n");
                }
                else {
                    logout();
                }
            }
            else if (choice == -1) {
                printf("학생종합정보시스템을 종료합니다.\n");
                break;
            }
            else {
                printf("잘못된 입력입니다. 학생종합정보시스템이 비정상적으로 종료됩니다.\n");
                break;
            }
        }
    }
}