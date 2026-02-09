import os
from dotenv import load_dotenv

# Load the .env file located next to this script (works regardless of cwd)
base_dir = os.path.dirname(__file__) # Get the directory of the current script 
dotenv_path = os.path.join(base_dir, 'database.env') # Construct the full path to the .env file
load_dotenv(dotenv_path) # Load environment variables from the specified .env file
# default dotenv_path is None, which means it will look for a .env file in the current working directory
os_version = os.getenv('OS')
print(f'The operating system version is: {os_version}')
database = os.getenv('database')
print(f'The database value is: {database}')

# load_dotenv() 默认寻找名为 .env 的文件并且按当前工作目录查找，
# 你的文件名是 database.env 且脚本从仓库根目录运行，所以没有被加载到，
# 导致 os.getenv('database') 返回 None。

