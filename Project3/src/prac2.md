# Q. 다음 코드는 Database 클래스의 일부분으로서 메서드가 세 개만 나와있다.<br>이 코드에 대해 JavaDoc 스타일에 맞게 주석을 추가해보자.

```
class Database{
    public:
        Employee& addEmployee(std::string const& firstName,
                              std::stirng const& lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(std::stirng const& firstName,
                              std::stirng cosnt& lastName);
}
```

---

# Solution. 

```
/**
 * The Database stores a collection of employees. It supports
 * adding and retrieving employees, and displaying employees
 * satisfying certain constraints.
 */
class Database
{
public:
	/**
	 * Adds an employee with given name to the database.
	 *
	 * @param firstName The first name of the employee to add.
	 * @param lastName The last name of the employee to add.
	 */
	Employee& addEmployee(const std::string& firstName,
		const std::string& lastName);

	/**
	 * Finds an employee based on an employee number.
	 *
	 * @param employeeNumber The employee number to find.
	 * @return The employee with given number.
	 * @throws logic_error When the requested employee cannot be found.
	 */
	Employee& getEmployee(int employeeNumber);

	/**
	 * Finds an employee based on a name.
	 *
	 * @param firstName The first name of the employee to find.
	 * @param lastName The last name of the employee to find.
	 * @return The employee with given name.
	 * @throws logic_error When the requested employee cannot be found.
	 */
	Employee& getEmployee(const std::string& firstName,
		const std::string& lastName);

	// Remainder omitted...
};

```