# Q. 다음 코드에서 서식과 관련하여 세 가지 부분을 수정해보자.<br>첫쨰. 중괄호를 별도 라인에 작성한다.<br>둘째, 중괄호를 적절히 들여쓴다.<br>셋째, 한 줄 짜리 코드 블록의 중괄호를 삭제한다.<br>이 예제를 통해 다양한 코드 서식을 직접 느껴보고 코드 서식이 가독성에 어떤 여향을 미치는지 확인해보자.

```
Employee& Database::getEmployee(int employeeNumber)
{
    for (auto& employee : m_employees) {
        if (employee.getEmployeeNumber() == employeeNUmber) {
            return employee;
        }
    }
    throw logic_error { "No employee found." };
}
```

---

# Soulution. 

- 중괄호를 별도 라인에 작성

```
Employee& Database::getEmployee(int employeeNumber)
{
    for (auto& employee : m_employees)
    {
        if (employee.getEmployeeNumber() == employeeNUmber) 
        {
            return employee;
        }
    }
    throw logic_error { "No employee found." };
}
```

- 중괄호를 적절히 들여쓰기

```
Employee& Database::getEmployee(int employeeNumber) {
    for (auto& employee : m_employees) {
        if (employee.getEmployeeNumber() == employeeNumber) {
            return employee;
        }
    }
    throw logic_error {"No employee found."};
}
```

- 한 줄 짜리 코드 블록의 중괄호 생략

```
Employee& Database::getEmployee(int employeeNumber) {
    for (auto& employee : m_employees) 
        if (employee.getEmployeeNumber() == employeeNumber) 
            return employee;
    throw logic_error {"No employee found."};
}
```