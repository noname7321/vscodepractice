from datetime import date,datetime,timedelta
import time
def get_current_date():
    """Returns the current date."""
    return date.today()
def inputbirthdaydate():
    """Prompt for birthday until a valid YYYY-MM-DD date is entered.
    This is tolerant to stray text (e.g. command echoes) by searching
    for the first YYYY-MM-DD pattern in the input.
    """
    import re
    while True:
        birthday = input("Enter your birthday date in YYYY-MM-DD format:").strip()
        # try to extract a YYYY-MM-DD pattern if user pasted extra text
        m = re.search(r"(\d{4}-\d{1,2}-\d{1,2})", birthday)
        candidate = m.group(1) if m else birthday
        try:
            year, month, day = map(int, candidate.split('-'))
            return date(year, month, day)  # Returns a date object representing the birthday date.
        except Exception:
            print("Invalid date format. Please enter date as YYYY-MM-DD (e.g. 1990-12-31).")
            continue

if __name__ == "__main__":
    now=time.time()
    print(now)
    print("Current timestamp is:" + str(now))
    print('Current local time is:',time.localtime(now))
    
    delta1=datetime.now() - datetime(2020, 1, 1)
    print(f"the type of delta1 is {type(delta1)}, and the value is {delta1}")

    td1=timedelta(days=5, hours=3, minutes=30)
    print(f"the type of td1 is {type(td1)}, and the value is {td1}")

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