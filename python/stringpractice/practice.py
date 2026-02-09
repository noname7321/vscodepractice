s="fedibuweiufbbwiunifnknkzjdndcqdwofwpqemfdowp"
word=input("Enter the word to search: ")
s.upper().count(word.upper())
print(f"The count of the word {word} is: {s.upper().count(word.upper())}")


try:
    score=input("Enter your score: ") #输入为字符串类型
    score=float(score) #转换为浮点数类型
    if 0<=score<=100:
        if score>=90:
            grade='A'
        elif score>=80:
            grade='B'
        elif score>=70:
            grade='C'
        elif score>=60:
            grade='D'
        else:
            grade='F'
        print(f"Your grade is: {grade}")
    else:
        raise ValueError("Score must be between 0 and 100.")
except Exception as e:
    print (f"Invalid input: {e}") #输出异常信息