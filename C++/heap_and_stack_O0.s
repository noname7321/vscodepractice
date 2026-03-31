	.file	"heap_and_stack.cpp"
	.text
	.section	.text$_ZN7Vector3C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7Vector3C1Ev
	.def	_ZN7Vector3C1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Vector3C1Ev
_ZN7Vector3C1Ev:
.LFB2191:
	pushq	%rbp			# 保存旧的基址寄存器，准备建立当前函数栈帧
	.seh_pushreg	%rbp
	movq	%rsp, %rbp		# rbp 指向当前栈帧基准，后面用固定偏移访问局部数据
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)	# 保存 this 指针/构造对象地址
	movq	16(%rbp), %rax	# 取出对象地址到 rax
	pxor	%xmm0, %xmm0		# xmm0 清零，得到 0.0f
	movss	%xmm0, (%rax)	# this->x = 0
	movq	16(%rbp), %rax	# 再次取出对象地址
	pxor	%xmm0, %xmm0		# xmm0 继续保持 0
	movss	%xmm0, 4(%rax)	# this->y = 0
	movq	16(%rbp), %rax	# 再次取出对象地址
	pxor	%xmm0, %xmm0		# xmm0 继续保持 0
	movss	%xmm0, 8(%rax)	# this->z = 0
	nop				# 空操作，通常只是对齐或占位
	popq	%rbp			# 恢复旧的基址寄存器
	ret				# 返回调用者
	.seh_endproc
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2192:
	pushq	%rbp			# 保存旧 rbp，建立 main 的栈帧
	.seh_pushreg	%rbp
	pushq	%rbx			# 保存被调用者需要保持的 rbx
	.seh_pushreg	%rbx
	subq	$120, %rsp		# 一次性在栈上开出 120 字节给局部变量/对齐/临时值
	.seh_stackalloc	120
	leaq	112(%rsp), %rbp	# rbp 设成栈帧基准，便于用负偏移访问局部变量
	.seh_setframe	%rbp, 112
	.seh_endprologue
 	call	__main			# MinGW 运行时初始化
	movl	$42, -4(%rbp)		# int value = 42;  value 放在栈上
	movl	$1, -64(%rbp)		# array[0] = 1;  数组在栈上连续存放
	movl	$2, -60(%rbp)		# array[1] = 2
	movl	$3, -56(%rbp)		# array[2] = 3
	movl	$4, -52(%rbp)		# array[3] = 4
	movl	$5, -48(%rbp)		# array[4] = 5
	leaq	-76(%rbp), %rax	# 取出栈上 vector 的地址
	movq	%rax, %rcx		# 第一个参数 this 指针放到 rcx
	call	_ZN7Vector3C1Ev	# 调用 Vector3 构造函数，初始化 vector
	movss	.LC1(%rip), %xmm0	# 装入常量 1.0f
	movss	%xmm0, -76(%rbp)	# vector.x = 1.0f;  直接写到栈上对象
	movl	$4, %ecx		# 申请 4 字节，等价于 new int
	call	_Znwy			# 调用 operator new(size_t)
	movq	%rax, -16(%rbp)	# hvalue = new int;  指针本身存在栈上
	movq	-16(%rbp), %rax	# 取出 hvalue 指向的堆地址
	movl	-4(%rbp), %edx	# 读取 value 的值 42
	movl	%edx, (%rax)	# *hvalue = value;  向堆内存写入 42
	movl	$20, %ecx		# 申请 20 字节，等价于 new int[5]
	call	_Znay			# 调用 operator new[](size_t)
	movq	%rax, -24(%rbp)	# harray = new int[5]
	movq	-24(%rbp), %rax	# 取出数组首地址
	movl	$1, (%rax)		# harray[0] = 1
	movq	-24(%rbp), %rax	# 重新取数组首地址
	addq	$4, %rax		# 指向 harray[1]
	movl	$2, (%rax)		# harray[1] = 2
	movq	-24(%rbp), %rax	# 重新取数组首地址
	addq	$8, %rax		# 指向 harray[2]
	movl	$3, (%rax)		# harray[2] = 3
	movq	-24(%rbp), %rax	# 重新取数组首地址
	addq	$12, %rax		# 指向 harray[3]
	movl	$4, (%rax)		# harray[3] = 4
	movq	-24(%rbp), %rax	# 重新取数组首地址
	addq	$16, %rax		# 指向 harray[4]
	movl	$5, (%rax)		# harray[4] = 5
	movl	$12, %ecx		# 申请 12 字节，等价于 new Vector3()
	call	_Znwy			# 分配堆内存给 hvec
	movq	%rax, %rbx		# 把返回的堆地址暂存在 rbx
	movq	%rbx, %rcx		# this 指针传给构造函数
	call	_ZN7Vector3C1Ev	# 在堆上构造一个 Vector3
	movl	$0, %eax		# 这里是编译器生成的临时标志，准备检查是否要释放
	movq	%rbx, -32(%rbp)	# hvec = 分配到的堆地址
	testb	%al, %al		# 检查 al 是否为 0
	je	.L3			# 如果为 0，跳过 delete 路径
	movl	$12, %edx		# delete 时传入对象大小（给调试/运行时使用）
	movq	%rbx, %rcx		# 把堆对象地址传给 delete
	call	_ZdlPvy			# 调用 operator delete(void*, size_t)
.L3:
	movq	-32(%rbp), %rax	# 取出 hvec 的堆地址
	movss	.LC1(%rip), %xmm0	# 装入 1.0f
	movss	%xmm0, (%rax)	# hvec->x = 1.0f;  写入堆对象成员
	movq	.refptr._ZSt3cin(%rip), %rax	# 取出 std::cin 的地址
	movq	%rax, %rcx		# this 指针传给 get()
	call	_ZNSi3getEv		# std::cin.get(); 等待用户按键
	movl	$0, %eax		# 返回 0
	addq	$120, %rsp		# 释放 main 的栈帧空间
	popq	%rbx			# 恢复 rbx
	popq	%rbp			# 恢复 rbp
	ret				# main 返回
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC1:
	.long	1065353216
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 15.2.0"
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_Znay;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
