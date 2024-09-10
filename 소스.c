#include <stdio.h>

int main()
{
    printf("회원가입을 시작하겠습니당\n");

    char studentID[10];
    char name[50];
    char phone[15];
    char gender[6];
    char email[30];
    char major[30];
    char password[20];

    printf("학번(=아이디)를 입력해주세요: ");
    scanf("%s", studentID);

    printf("이름을 입력해주세요: ");
    scanf("%s", name);

    printf("전화번호를 입력해주세요: ");
    scanf("%s", phone);

    printf("성별을 입력해주세요(ex: 남자/여자): ");
    scanf("%s", gender);

    printf("이메일을 입력해주세요: ");
    scanf("%s", email);

    printf("본인의 학과를 입력해주세요: ");
    scanf("%s", major);

    printf("비밀번호를 입력해주세요: ");
    scanf("%s", password);

    printf("회원가입이 성공적으로 완료되었습니당\n");

    printf("로그인을 시작하겠습니당\n");

    char correct_id[] = "USER1234";
    char correct_password[] = "PASSWORD1234";

    char input_id[50];
    char input_password[50];

    printf("아이디를 입력하세요: ");
    scanf("%s", input_id);
    printf("암호를 입력하세요: ");
    scanf("%s", input_password);

    int id_match = (strcmp(input_id, correct_id) == 0);
    int password_match = (strcmp(input_password, correct_password) == 0);

    if (id_match && password_match) {
        printf("로그인 성공!\n");
    }
    else {
        printf("로그인 실패ㅜ.ㅜ 아이디 또는 암호가 올바르지 않습니다.\n");
    }

    return 0;
}