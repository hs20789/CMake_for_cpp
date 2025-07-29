# 아래의 코드의 주석에 문제가 있는가? 그렇다면 이유는 뭘까? 더 나은 방법이 있다면 제시해보자.

```
void Database::displayCurrent() const           // The displayCurrent() method.
{
	for (const auto& employee : m_employees) {  // For each employee...
		if (employee.isHired()) {               // If the employee is hired
			employee.display();                 // Then display that employee
		}
	}
}
```


---

# Solution

- 이미 해당 코드의 변수 이름이나 함수 이름등으로 해당 코드의 역할을 충분히 알 수 있으므로 주석을 생략

```
void Database::displayCurrent() const           
{
	for (const auto& employee : m_employees) {  
		if (employee.isHired()) {               
			employee.display();                 
		}
	}
}
```


