/* 
  파일이름: C언어 1차과제
  작 성 자: 60231920_김학진
  하 는 일: 이자카야 주문 시스템 만들기
*/

#include <stdio.h>

int main()
{
   // 메뉴 가격 및 변수 선언
  int drink_price = 5000;
  int potato_price = 6000;
  int chicken_price = 9000;
  int total_price = 0;

  int drink_count = 0;
  int potato_count = 0;
  int chicken_count = 0;

  double discount_rate = 0.05;
  double total_price_with_discount = 0;

  char order = 'y';

  int service_choice;
  double day_result = 0;

  // 첫 화면 출력
  printf("첫번째 손님이 입장하셨습니다.\n");

  printf("========================\n");
  printf("이자카야에 오신 것을 환영합니다\n");
  printf("메뉴판을 보시려면 아무 알파벳이나 눌러주세요\n");
  printf("========================\n");
  scanf("%c", &order);

  // 메뉴판 출력
  printf("====== 이자카야 메뉴판 ======\n");
  printf("술(5000원)\n");
  printf("감자칩(6000원)\n");
  printf("치킨(9000원)\n");
  printf("=============================\n");

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
  printf("추가 주문을 하시겠습니까? (동의 시 y)\n");
  scanf(" %c", &order);

  if(order == 'y')
  {
    int add_drink;
    int add_potato;
    int add_chicken;

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
  total_price_with_discount = total_price * ( 1 - discount_rate );

  printf("=========================\n");
  printf("주문 내역\n");
  printf("술: %d병\n", drink_count);
  printf("감자칩: %d개\n", potato_count);
  printf("치킨: %d개\n", chicken_count);
  printf("할인율 적용 후 총 결제 금액: %.2lf원 \n", total_price_with_discount);
  printf("=========================\n\n");

  printf("결제 금액을 확인하셨다면 아무 알파벳이나 눌러주세요 : ");
  scanf(" %c", &order);

  // 손님 응대하기
  printf("\n=========================\n");
  printf("[상황] 손님이 서비스 안주를 요청합니다.\n\n");

  printf("1. 친절하게 서비스를 가져다준다.\n");
  printf("2. 바쁘다며 거절한다.\n\n");

  printf("[상황] 어떻게 하시겠습니까? (1 또는 2) : ");
  scanf("%d", &service_choice);

  if(service_choice == 1)
  {
    printf("=========================\n\n");
    printf("손님이 감동하여 팁 2000원을 건넸습니다.\n\n");
    day_result += 2000;
  }
  else if(service_choice == 2)
  {
    printf("=========================\n\n");
    printf("손님이 기분이 상해 1000원 할인을 요구합니다.\n\n");
    day_result -= 1000;
  }
  else
  {
    printf("=========================\n\n");
    printf("선택지의 숫자를 입력해주세요.\n");
  }

  // 하루의 총 매출 계산
  day_result += total_price_with_discount;
  printf("=========================\n");
  printf("오늘의 총 매출액 : %.2lf원 \n", day_result);
  
  return 0; 
}
