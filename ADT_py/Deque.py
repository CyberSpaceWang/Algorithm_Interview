# -*- coding: utf-8 -*-
'''
2019-10.10
双端队列的Python实现
'''

class deque(object):
	"""docstring for deque"""
	def __init__(self):
		self.items = []
	
	def push_back(self, item):
		self.items.append(item)
	
	def push_front(self, item):
		self.items.insert(0, item)
	
	def pop_back(self):
		self.items.pop()
	
	def pop_front(self):
		self.items.pop(0)
	
	def empty(self):
		return self.items == []
	
	def size(self):
		return len(self.items)
	

