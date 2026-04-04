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
  int potatochips_price = 6000;
  int chicken_price = 9000;
  int total_price = 0;

  int drink_count = 0;
  int potatochips_count = 0;
  int chicken_count = 0;

  float discount_rate = 0.05;
  float total_price_with_discount = 0;

  char order = 'y';

  // 첫 화면 출력
  printf("========================\n");
  printf("이자카야에 오신 것을 환영합니다\n");
  printf("메뉴판을 보시겠습니까? (y/n)\n");
  printf("========================\n");
  scanf("%c", &order);

  // 메뉴판 출력
  printf("====== 이자카야 메뉴판 ======\n");
  printf("술(5000원)\n");
  printf("감자칩(6000원)\n");
  printf("치킨(9000원)\n");

  // 메뉴 수량 입력 + 금액 합산
  printf("술의 수량을 입력하세요 : ");
  scanf("%d", &drink_count);
  total_price = total_price + drink_price * drink_count;

  printf("감자칩의 수량을 입력하세요 : ");
  scanf("%d", &potatochips_count);
  total_price = total_price + potatochips_price * potatochips_count;

  printf("치킨의 수량을 입력하세요 : ");
  scanf("%d", &chicken_count);
  total_price = total_price + chicken_price * chicken_count;

  total_price_with_discount = total_price * ( 1 - discount_rate );

  // 할인율 적용 후 총액 계산
  printf("=========================\n");
  printf("주문 내역\n");
  printf("술: %d병\n", drink_count);
  printf("감자칩: %d개\n", potatochips_count);
  printf("치킨: %d개\n", chicken_count);
  printf("기본 할인 5프로 적용 후 총 결제 금액: %.2f원", total_price_with_discount);
  
  return 0; 
}
