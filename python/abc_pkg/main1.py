import abc_pkg.my_abc as abc_package
abc_package.my_function()
#原因: 当直接运行 python abc_pkg\main.py 或用 Run File 时，
# 解释器把该文件目录（.../abc_pkg）放到 sys.path[0]，
# 这让解释器在该目录下查找模块名 abc_pkg 而找不到包根目录，
# 所以无法导入 abc_pkg。另外，直接运行文件不会触发包相对导入（. 导入）行为。
# cd c:\Users\abc\Documents\GitHub\vscodepractice\python
# python -m abc_pkg.main会把 abc_pkg.main 当作一个「可执行模块」来运行。
# Python 会在 sys.path 中查找 abc_pkg 包，先导入并执行 __init__.py，
# 然后以 __name__ == "__main__" 的方式执行 abc_pkg/main.py
# （模块内部的相对导入和包上下文都生效）。
print('-'*20)
from abc_pkg import my_abc as b
b.my_function()

#    - 包已经在当前进程中被导入过一次：`__init__.py` 只在第一次导入时
#      执行，之后再次导入同一包不会重新执行 `__init__.py`（除非你显式
#      卸载模块并重新导入）。
from abc_pkg.my_abc import my_function
my_function()