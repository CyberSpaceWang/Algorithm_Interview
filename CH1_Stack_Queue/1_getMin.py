'''
2019-10.25
CH1 栈--设计一个有getMin功能的栈，测试用例
6
push 3
push 2
push 1
getMin
pop
getMin
'''
import pdb


n = int(input().strip())
stack = []
stack_min = []
for _ in range(n):
	x = input().split()
	pdb.set_trace()

	# print(x)
	if x[0] == "push":
		num = int(x[1])      # 大坑--必须进行int()类型转换,否则存入的是字符串,负数时有bug
		stack.append(num)
		if stack_min == [] or stack_min[-1] >= num:
			stack_min.append(num)
		else:
			stack_min.append(stack_min[-1])
	elif x[0] == "pop":
		stack_min.pop()
		stack.pop()
	else:
		print(stack_min[-1])


