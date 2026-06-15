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

  if(guest_counter > 0)
  {
    printf("\n [손님별 결제 내역] \n");

    for(int i=0; i<guest_counter; i++)
    {
      printf("%d번째 손님의 결제 금액 : %.2lf원 \n", i+1, guest_payments[i]);
    }

    double *ptr = guest_payments;
    double max_payment = *ptr;

    for(int i=0; i<guest_counter; i++)
    {
      if(*(ptr+i) > max_payment)
      {
        max_payment = *(ptr+i);
      }
    }
    printf("\n 오늘의 최고 결제 금액 : %.2lf원 \n", max_payment);

    double average_payment = cal_average(guest_payments, guest_counter);
    printf("오늘 손님들의 1인당 평균 결제 금액 : %.2lf원 \n", average_payment);
  }
  else
  {
    printf("\n 오늘 방문한 손님이 없습니다. \n");
  }

  printf("오늘의 총 매출액 : %.2lf원 \n", day_result);
  
  return 0; 
}

// 함수 정의
void show_menu()
{
  char order = 'y';

  printf("========================\n");
  printf("이자카야에 오신 것을 환영합니다\n");
  printf("메뉴판을 보시려면 아무 알파벳이나 눌러주세요\n");
  printf("========================\n");
  scanf(" %c", &order);

  // 메뉴판 출력
  printf("====== 이자카야 메뉴판 ======\n");
  printf("술(5000원)\n");
  printf("감자칩(6000원)\n");
  printf("치킨(9000원)\n");
  printf("============================\n");
}

double cal_order()
{
  int drink_price = 5000;
  int potato_price = 6000;
  int chicken_price = 9000;
  int total_price = 0;
    
	int drink_count = 0;
  int potato_count = 0;
  int chicken_count = 0;
	double discount_rate = 0;
  double final_price = 0;

  // 메뉴 수량 입력 + 금액 합산
  printf("술의 수량을 입력하세요 : ");
  scanf("%d", &drink_count);
  total_price = total_price + drink_price * drink_count;

  printf("감자칩의 수량을 입력하세요 : ");
  scanf("%d", &potato_count);
  total_price = total_price + potato_price * potato_count;

  printf("치킨의 수량을 입력하세요 : ");
  scanf("%d", &chicken_count);
  total_price = total_price + chicken_price * chicken_count;

  //추가 주문 여부 묻기
  char order = 'y';
  printf("추가 주문을 하시겠습니까? (동의 시 y)\n");
  printf("추가 주문을 원치 않으시면 y를 제외한 알파벳을 눌러주세요.\n");
  scanf(" %c", &order);

  if(order == 'y')
  {
    int add_drink = 0;
    int add_potato = 0;
    int add_chicken = 0;

    printf("추가로 주문할 술의 수량을 입력하세요 : ");
    scanf("%d", &add_drink);

    printf("추가로 주문할 감자칩의 수량을 입력하세요 : ");
    scanf("%d", &add_potato);

    printf("추가로 주문할 치킨의 수량을 입력하세요 : ");
    scanf("%d", &add_chicken);

    total_price += drink_price * add_drink;
    total_price += potato_price * add_potato;
    total_price += chicken_price * add_chicken;

    drink_count += add_drink;
    potato_count += add_potato;
    chicken_count += add_chicken;
  }
  else
  {
    printf("주문이 완료되었습니다.\n\n");
  }

  // 결제 금액에 따른 할인율 적용
  if(total_price >= 100000)
  {
    discount_rate = 0.2;
  }
  else if(total_price >= 50000)
  {
    discount_rate = 0.1;
  }
  else
  {
    discount_rate = 0;
  }

  // 할인율 적용 후 총액 계산
  final_price = total_price * ( 1 - discount_rate );

  printf("=========================\n");
  printf("[주문 내역]\n");
  printf("술: %d병\n", drink_count);
  printf("감자칩: %d개\n", potato_count);
  printf("치킨: %d개\n", chicken_count);
  printf("할인율 적용 후 총 결제 금액: %.2lf원 \n", final_price);
  printf("=========================\n\n");

  printf("결제 금액을 확인하셨다면 아무 알파벳이나 눌러주세요 : ");
  scanf(" %c", &order);

  // 음식 매출 우선 누적
  day_result += final_price;

  return final_price;
}



