#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("회원가입을 원하시면 1, 로그인을 원하시면 2를 입력하시요!\n 만약 종료를 원한다면 -1를 입력하세요:\n ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("회원가입을 시작하겠어요 축하축하\n");

            char string[6][162];

            printf("가입하실 이름을 입력하세요.\n !세상에서 가장 긴 이름은 161자랍니다. 당신이 기네스 기록을 세울 수 있는게 아니라면 제발 161자 내로 입력하세요!:\n");
            scanf("%161s", string[0]);

            printf("가입에 필요한 전화번호를 번호만 입력하세요.\n 제발 부탁이에요. 진짜 제발:");
            scanf("%11s", string[1]);

            printf("소속 학부 또는 소속 학과 입력하세요.(최대 10글자 이내):\n");
            scanf("%10s", string[2]);

            printf("학번을 입력하시요.:\n");
            scanf("%8s", string[3]);

            printf("가입에 필요한 이메일을 입력해 주실래요? :\n");
            scanf("%20s", string[4]);

            printf("비밀번호를 설정하세요!(중요중요대중요)\n (숫자, 영문, 한글, 기호 뭐든 그냥 니가 하고 싶은거로 하세요 그냥; 그 대신 10자 이내여야해요 !):\n");
            scanf("%10s", string[5]);

            printf("가입을 진심진심정말정말루 축하드립니다!!!(축복의 빵빠레)\n");

        } else if (choice == 2) {

            printf("로그인의 시간이에요");

            char string[6][162];

            printf("이름을 입력하세요.:\n");
            scanf("%161s", string[0]);

            printf("가입에 사용한 전화번호를 번호만 입력하세요.\n 제발 부탁이에요. 진짜 제발:\n");
            scanf("%11s", string[1]);

            printf("소속 학부 또는 소속 학과 입력하세요.(최대 10글자 이내):\n");
            scanf("%10s", string[2]);

            printf("학번을 입력하시요.:\n");
            scanf("%8s", string[3]);

            printf("가입에 사용한 이메일을 입력해 주실래요? :\n");
            scanf("%20s", string[4]);

            printf("비밀번호를 입력하세요!(중요중요대중요)\n (신중한 입력 부탁드려요 10자 이내여야해요 !):\n");
            scanf("%10s", string[5]);

        } else if (choice == -1) {
            printf("프로그램을 종료합니다.\n");
            break;

        } else {
            printf("오류로 인해 종료합니다.\n");
            break;
        }
    }

    return 0;
}
