def get_inital(name,force_upper=True):
    if force_upper:
        return name[0].upper()
    return name[0].lower()

first_name = input("Enter your first name: ")
initial = get_inital(first_name)
second_name = input("Enter your second name: ")
second_initial = get_inital(force_upper=False, name=second_name)
# when use named arguments, the order does not matter
print("Your initial is:", initial)