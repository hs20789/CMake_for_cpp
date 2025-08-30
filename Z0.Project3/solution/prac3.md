# Q. 다음 명명 규칙에 몇 가지 문제가 있다. 모두 찾아서 해결해보라.

```
class xrayController{
    public:
        // 1. 능동 엑스레이 전류를 암페어 단위로 가져온다.
        double getCuttent() const;

        // 2. 엑스레이의 전류를 인수로 지정한 암페어 단위 값으로 설정한다.
        void setIt(double Val);

        // 3. 전류를 0암페어로 설정
        void 0Current();

        // 4. 엑스레이 소스 타입을 가져온다.
        std::string cosnt& getSourceType() const;
}
```

# Solution.

```
class XrayController                                           //// xrayController: Class names start with an uppercase letter.
{
public:
	// Gets the active X-ray current in µA.
	double getCurrent() const;

	// Sets the current of the X-rays to the given current in µA.
	void setCurrent(double currentInMicroAmp);                 //// setIt(): too generic name.
	                                                           //// Val: parameters start with a lowercase letter.
	                                                           ////      and should have a meaningful name

	// Sets the current to 0 µA.
	void setZeroCurrent();                                     //// 0Current(): identifiers are not allowed to start with a digit.

	// Gets the X-ray source type.
	const std::string& getSourceType() const;

	// Sets the X-ray source type.
	void setSourceType(std::string_view type);                 //// _Type: identifiers should not start with an underscore followed by a capital.

private:
	double m_current; // The X-ray current in µA.              //// d: too short and meaningless. Data members start with m_
	std::string m_sourceType; // The type of the X-ray source. //// m_src__type: Double underscores and abbreviations are not allowed. 
};

```