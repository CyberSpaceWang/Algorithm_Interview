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
		self.items.pop()
	
	def top(self):
		return self.items[len(self.items)-1]
		
	def size(self):
		return len(self.items)


if __name__ == '__main__':    # 测试
	s = stack()
	s.push(1)
	s.push(2)
	s.push(3)
	print(s.size())
	while not s.empty():
		print(s.top())
		s.pop()
	