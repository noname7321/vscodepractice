days_in_feb=28
print("Days in February:", days_in_feb)
print("Days in February: {}".format(days_in_feb))
#print("Days in February:"+ days_in_feb) # This will cause an error, 
# because days_in_feb is an integer, not a string. so it needs to be converted to a string first.
print("Days in February: " + str(days_in_feb))
print(f"Days in February: {days_in_feb}")
num1='1'
num2='2'
print("Concatenated string:", num1 + num2)
print("Sum of numbers:", int(num1) + int(num2))
print(f"Sum of numbers: {int(num1) + int(num2)}")
num1=input("Enter first number: ")
num2=input("Enter second number: ")
print("Concatenated string of entered numbers:", num1 + num2)

print(f"Sum of entered numbers: {float(num1) + float(num2)}")
print(f"Sum of entered numbers: {int(num1) + int(num2)}")
# This will work only if the entered numbers are integers.