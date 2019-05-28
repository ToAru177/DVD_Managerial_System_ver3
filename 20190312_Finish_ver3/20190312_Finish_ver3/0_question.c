/*
[문제 1] DVD 대여 기능을 구현하세요.
아래의 사항을 모두 만족해야 합니다.
- 대여 시 저장해야 할 정보는 '대여 고객 ID' 와
  '대여 날짜' 두 가지로 제한한다.
  그리고, 대여 날짜는 자동 삽입되는 형식이 아니라
  프로그램 사용자가 직접 입력하는 방식으로 구현한다.
- 대여 상태에 있는 DVD를 대여하려 할 경우, 다음과
  같은 메세지를 출력하고 대여 절차를 중단한다.
  "대여 중인 DVD이므로, 대여가 불가능합니다."
- 대여 과정에 입력된 고객 ID가 유효하지 않으면 다음
  메세지를 출력하고 대여 절차를 중단한다.
  "입력된 ID로 가입된 고객이 없습니다."


[문제 2] DVD 반납 기능을 구현하세요.
- 반납할 DVD의 ISBN만 입력하면 반납이 되도록 한다.
- 등록되지 않은 DVD의 ISBN을 입력하면서 반납을 시도
  하려 하면, 다음과 같은 메세지를 출력하고, 반납 과정
  을 중단한다.
  "등록되지 않은 DVD ISBN입니다."
- 대여되지 않은 DVD의 ISBN을 입력하면서 반납을 시도
  하려 하면, 다음과 같은 메세지를 출력하고, 반납과정
  을 중단한다.
  "대여되지 않은 DVD입니다."


[문제 3] 특정 DVD의 대여자 전체 정보를 출력하는 
  기능을 구현하세요.
- 예를 들어, ISBN이 777-77-7777인 DVD의 대여 정보를
  출력하라는 요청이 있으면, 지금까지 이 DVD를 대여한
  모든 고객의 ID, 이름, 전화번호, 대여날짜를 출력해야
  한다.
*/