from datetime import date,datetime,timedelta
def get_current_date():
    """Returns the current date."""
    return date.today()
def inputbirthdaydate():
    birthday=input("Enter your birthday date in YYYY-MM-DD format:")
    year,month,day=map(int,birthday.split('-'))
    return date(year,month,day)# Returns a date object representing the birthday date.

if __name__ == "__main__":
    print("Current date is:", get_current_date())
    print("Today is:" + str(datetime.now()))
    print("Current year is:" + str(datetime.now().year))
    print("Current month is:" + str(datetime.now().month))
    print("Current day is:" + str(datetime.now().day))
    future_date = datetime.now() + timedelta(days=10)
    print("Date after 10 days will be:" + str(future_date))
    past_date = datetime.now() - timedelta(days=10)
    print("Date 10 days ago was:" + str(past_date))
    specific_date = date(2023, 2, 28)
    print("Specific date is:" + str(specific_date))
    specific_date = date(2024, 2, 29)
    print("Specific date is:" + str(specific_date))
    birthday_date = inputbirthdaydate()
    print("Your birthday date is:" + str(birthday_date))