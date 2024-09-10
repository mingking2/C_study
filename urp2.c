#include <stdio.h>

int main() {


	char id[15], name[50], num[15], gen[10], ema[50], dep[50], pass[50];

	char id2[15], pass2[50];

	int a, b;


	printf("원호대학교에 입학을 축하드립니다!!\n");
	printf("회원가입을 시작하겠습니다\n\n");

	//회원가입

	printf("학번(=아이디)를 입력하시오\n");
	scanf_s("%14s", id, 15);

	printf("이름을 입력하시오\n");
	scanf_s("%49s", name, 50);

	printf("전화번호를 입력하시오 (- 제외)\n");
	scanf_s("%14s", num, 15);

	printf("성별을 입력하시오(남:ma 여:wo) \n");
	scanf_s("%9s", gen, 10);

	if (strcmp(gen, "ma") != 0 && strcmp(gen, "wo") != 0) {
		printf("오류로 인해 종료되었습니다");
		return 0;
	}
	printf("이메일을 입력하시오 \n");
	scanf_s("%49s", ema, 50);

	printf("학과를 입력하시오 \n");
	scanf_s("%49s", dep, 50);

	printf("비밀번호를 입력하시오 \n");
	scanf_s("%49s", pass, 50);

	printf("\n\n");


	char* sign[] = { id, name, num, gen, ema, dep, pass };


	//로그인

	while (1) {

		printf("로그인을 시작하겠습니다\n\n");
		printf("아이디(=학번)를 입력하시오\n");
		scanf_s("%14s", id2, 15);
		printf("비밀번호를 입력하시오\n");
		scanf_s("%49s", pass2, 50);


		if (strcmp(id2, id) != 0 || strcmp(pass2, pass) != 0) {
			printf("아이디 혹은 비밀번호가 잘못 입력되었습니다.\n");
		}
		else {
			printf("로그인 되었습니다\n");
			break;
		}
     
	}
	
	//메인메뉴

	while (1) {

		printf("\n무엇을 하시겠습니까?\n");
		printf("로그인(0을 입력), 로그아웃(1을 입력), 마이페이지 조회(2를 입력), 종료(-1을 입력)\n");
		scanf_s("%d", &a);

		if (a == -1) {

			printf("프로그램이 종료되었습니다.");

			return 0;

		}

		else if (a == 0) {

			printf("아이디(=학번)를 입력하시오\n");
			scanf_s("%14s", id2, 15);
			printf("비밀번호를 입력하시오\n");
			scanf_s("%49s", pass2, 50);

		}

		else if (a == 1) {
			printf("로그아웃 되었습니다\n");
			
		}

		else if (a == 2) {

			printf("\n마이페이지 조회!\n");
			printf("학번: %s\n", id);
			printf("이름: %s\n", name);
			printf("전화번호: %s\n", num);
			printf("성별: %s\n", gen);
			printf("이메일: %s\n", ema);
			printf("학과: %s\n", dep);
			printf("비밀번호는 보안상 비밀 ~~!! \n");

		}

	}

	return 0;

	}

