# -*- coding: utf-8 -*-
'''
2019-10.10
队列的Python实现
'''

class queue():
	def __init__(self):
		self.items = []
		
	def push(self, item):
		self.items.append(item)
	
	def pop(self):
		self.items.pop(0)      # pop(location)
	
	def front(self):
		return self.items[0]
		
	def empty(self):           # 等于空则返回1
		return self.items == []
	
	def size(self):
		return len(items)
	
	def clear(self):
		while not self.items.empty():
			self.items.pop()


if __name__ == '__main__':
	q = queue()
	q.push(1)
	q.push(2)
	q.push(3)
	q.clear()
	
	
	