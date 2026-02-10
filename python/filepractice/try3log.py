import time

def show_info():
    print("please enter number:0-exit,1-log current time")

def write_log(username='default_user'):
    with open('log.txt','a',encoding='utf-8') as f:
        current_time=time.strftime('%Y-%m-%d %H:%M:%S',time.localtime())
        f.write(current_time+'\n')
        print(f'useername:{username}Logged time: {current_time}')

def read_log():
    with open('log.txt','r',encoding='utf-8') as f:
        for line in f:
            print(line.strip())

if __name__ == "__main__":
    while True:
        show_info()
        choice=input("Enter your choice:")
        if choice=='0':
            print("Exiting program.")
            break
        elif choice=='1':
            write_log()
        else:
            print("Invalid choice, please try again.")