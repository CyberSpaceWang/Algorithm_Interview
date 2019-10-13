# -*- coding: utf-8 -*-
'''
2019-10.10
栈的实现,测试在main中,直接命令行执行即可
'''
class stack():
	def __init__(self):
		self.items = []
	
	def empty(self):       # 等于空返回1
		return self.items == []
	
	def push(self, item):
		self.items.append(item)
	
	def pop(self):
		return self.items.pop()     # 弹出并返回
	
	def top(self):
		return self.items[len(self.items)-1]
		
	def size(self):
		return len(self.items)
		
	def clear(self):                # 类中的成员函数访问成员变量或成员函数
		while not len(self.items) == 0:
			self.items.pop()        # 使用self.pop()同样可以实现

if __name__ == '__main__':    # 测试
	s = stack()
	s.push(1)
	s.push(2)
	s.push(3)
	print(s.size())
	s.clear()
	print(s.size())
	