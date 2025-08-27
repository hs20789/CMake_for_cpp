## 분할(partition)에 대해 설명해보자

---

## Solution.

어떤 조건(단항 predicate p(x))이 주어졌을 때, 시퀀스(구간) `[first, last)`를

p(x) == true인 원소들이 앞쪽에,

p(x) == false인 원소들이 뒤쪽에
오도록 제자리(in-place) 재배치하면 이 구간은 그 조건에 대해 partitioned 상태라고 합니다.
경계 지점(첫 번째 false의 위치)을 partition point라고 부릅니다.

정렬(sort)과 달리 상대적 순서는 보장되지 않습니다(안정성이 필요하면 stable_partition 사용).