## Q. 재사용 가능한 코드 설계를 위한 최선의 전략은?

---

## Solution.

재사용할 수 있는 코드를 설계하는 데 가장 중요한 부분은 추상화(abstraction)다. 
추상화의 핵심은 인터페이스와 구현을 실질적으로 분리하는 데 있다.

재사용에 최적화된 코드는 다음과 같은 특징을 갖는다

- 서로 관련 없거나 논리적으로 구분되는 개념이 독립적인 컴포넌트로 구성된다.
> 결합도를 낮추고, 응집도를 높여야 한다. -> 단일 책임 원칙(SRP)
- 범용 데이터 구조와 알고리즘을 템플릿으로 구성
- 적절한 검사 기능과 안전장치 제공하기
- 확장성을 고려한 설계
