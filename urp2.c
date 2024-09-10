#include <stdio.h>
#include <string.h> 

int main() {
   
    char id[15], name[50], num[15], gen[10], ema[50], dep[50], pass[50];   // 사용자 정보를 저장할 문자열 배열 선언
    char id2[15], pass2[50]; // 로그인 시 입력 받을 아이디와 비밀번호
    int a; // 메뉴 선택을 위한 변수

    // 프로그램 시작
    printf("원호대학교에 입학을 축하드립니다!!\n");
    printf("회원가입을 시작하겠습니다\n\n");

    // 회원가입 단계
    printf("학번(=아이디)를 입력하시오\n");
    scanf_s("%14s", id, 15); // 최대 14자까지 입력받아 id에 저장

    printf("이름을 입력하시오\n");
    scanf_s("%49s", name, 50); // 최대 49자까지 입력받아 name에 저장

    printf("전화번호를 입력하시오 (- 제외)\n");
    scanf_s("%14s", num, 15); // 최대 14자까지 입력받아 num에 저장

    printf("성별을 입력하시오(남:ma 여:wo) \n");
    scanf_s("%9s", gen, 10); // 최대 9자까지 입력받아 gen에 저장

    // 성별 입력 확인
    if (strcmp(gen, "ma") != 0 && strcmp(gen, "wo") != 0) {
        printf("오류로 인해 종료되었습니다");
        return 0; // 잘못된 입력 시 프로그램 종료
    }

    printf("이메일을 입력하시오 \n");
    scanf_s("%49s", ema, 50); // 최대 49자까지 입력받아 ema에 저장

    printf("학과를 입력하시오 \n");
    scanf_s("%49s", dep, 50); // 최대 49자까지 입력받아 dep에 저장

    printf("비밀번호를 입력하시오 \n");
    scanf_s("%49s", pass, 50); // 최대 49자까지 입력받아 pass에 저장

    printf("\n\n");

    // 사용자 정보를 배열에 저장
    char* sign[] = { id, name, num, gen, ema, dep, pass };

    // 로그인
    while (1) {
        printf("로그인을 시작하겠습니다\n\n");
        printf("아이디(=학번)를 입력하시오\n");
        scanf_s("%14s", id2, 15); // 로그인할 아이디 입력받기
        printf("비밀번호를 입력하시오\n");
        scanf_s("%49s", pass2, 50); // 로그인할 비밀번호 입력받기

        // 입력된 아이디와 비밀번호 검증
        if (strcmp(id2, id) != 0 || strcmp(pass2, pass) != 0) {
            printf("아이디 혹은 비밀번호가 잘못 입력되었습니다.\n");
        }
        else {
            printf("로그인 되었습니다\n");
            break; // 로그인 성공 시 루프 탈출
        }
    }

    // 메인 메뉴
    while (1) {
        printf("\n무엇을 하시겠습니까?\n");
        printf("로그인(0을 입력), 로그아웃(1을 입력), 마이페이지 조회(2를 입력), 종료(-1을 입력)\n");
        scanf_s("%d", &a); // 메뉴 선택 입력받기

        if (a == -1) {
            printf("프로그램이 종료되었습니다.");
            return 0; // 종료 선택 시 프로그램 종료
        }
        else if (a == 0) {
            printf("아이디(=학번)를 입력하시오\n");
            scanf_s("%14s", id2, 15); // 로그인 아이디 재입력
            printf("비밀번호를 입력하시오\n");
            scanf_s("%49s", pass2, 50); // 로그인 비밀번호 재입력
        }
        else if (a == 1) {
            printf("로그아웃 되었습니다\n"); // 로그아웃 메시지
        }
        else if (a == 2) {
            // 마이페이지 조회
            printf("\n마이페이지 조회!\n");
            printf("학번: %s\n", id); // 학번 출력
            printf("이름: %s\n", name); // 이름 출력
            printf("전화번호: %s\n", num); // 전화번호 출력
            printf("성별: %s\n", gen); // 성별 출력
            printf("이메일: %s\n", ema); // 이메일 출력
            printf("학과: %s\n", dep); // 학과 출력
            printf("비밀번호는 보안상 비밀 ~~!! \n"); // 비밀번호는 숨김
        }
    }

    return 0; // 프로그램 종료
}