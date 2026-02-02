def main():
	first_name = input("Enter your first name: ")
	last_name = input("Enter your last name: ")
	print("Hello, " + first_name.capitalize() + " " + last_name.capitalize() + "! Welcome to the program.")
	print('Hello, {} {}! Welcome to the program.'.format(first_name.capitalize(), last_name.capitalize()))
	print('Hello, {0} {1}! Welcome to the program.'.format(first_name.capitalize(), last_name.capitalize()))
	print(f'Hello, {first_name.capitalize()} {last_name.capitalize()}! Welcome to the program.')
# The above line is an f-string, which allows you to embed expressions inside string literals,
# using curly braces {}. It is available in Python 3.6 and later.
# f-strings are more readable and concise than other string formatting methods.
# They also allow for more complex expressions, such as function calls and arithmetic operations,
# to be embedded directly in the string.

# The above lines demonstrate several string formatting methods and are executed
# only when this file is run as a script, not when it is imported.

if __name__ == '__main__':
	main()
	table = str.maketrans("ae", "12", "x")#把字符 'a' 映射为 '1'，把 'e' 映射为 '2'，并把第三个参数中的字符（此处为 'x'）标记为应被删除
	print("example".translate(table))