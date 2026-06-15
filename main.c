/* 
  파일이름: C언어 1차과제
  작 성 자: 60231920_김학진
  하 는 일: 이자카야 주문 시스템 만들기
*/

#include <stdio.h>

int guest_counter = 0; // 손님 수 증가를 전역 변수로 선언
double day_result = 0; // 하루 총 매출을 전역 변수로 선언

// 함수 선언
void show_menu();
double cal_order();
void handle_service(double current_pay);
double cal_average(double *arr, int count);

// main함수 선언
int main()
{
  int drink_count = 0;
  int potato_count = 0;
  int chicken_count = 0;

  double guest_payments[100] = {0}; // 배열 선언

  // 첫 화면 출력
  printf("=============================\n");
	printf("이자카야 아르바이트 시뮬레이션 \n");
	printf("=============================\n");

  // 무한 반복문 구현
  while(1)
  {
    int choice;

    printf("=============================\n");
    printf("1. 새로운 손님 받기 \n");
    printf("2. 영업 마감 \n");
    printf("=============================\n");
    printf("원하는 기능을 선택하세요 : ");
    scanf("%d", &choice);

    if(choice == 2)
    {
      printf("영업을 마감합니다. \n");
      break;
    }
    
    switch(choice == 1)
    {
      case 1:
        {
          guest_counter ++;
          printf("%d번째 손님이 입장하셨습니다.\n", guest_counter);

          show_menu(); // 1번 함수 호출

          double total_price_with_discount = cal_order(); // 2번 함수 호출

          if(guest_counter <= 100)
          {
            guest_payments[guest_counter - 1] = total_price_with_discount;
          }

          handle_service(total_price_with_discount); // 3번 함수 호출
          
          printf("%d번 손님의 응대가 끝났습니다.\n", guest_counter);
          break;
        }  
      default:
        {
          printf("\n올바른 번호를 입력해주세요.\n");
          break;
        }  
    }  
  }  

  // 하루의 총 매출 계산
  day_result += total_price_with_discount;
  printf("=========================\n");
  printf("오늘 방문한 총 손님 수 : %d명 \n", guest_counter);
  printf("오늘의 총 매출액 : %.2lf원 \n", day_result);
  
  return 0; 
}
