import myScalar
import myString

class myMatrix:

	# for initialize empty matrix
	def __initEmpty(self, row, col):
		if row <=0 or col <= 0:
			raise NameError('Initialization Fail')
		self.row = row
		self.col = col
		self.val = [([float()] * col) for i in range(row)]

	def __init__(self, row, col, val=[]):
		# for empty matrix
		if not val:
			self.__initEmpty(row,col)
			return
		# check the input parameter
		if type(val)!=list or not all(isinstance(v,float) for v in val) or len(val)!=row*col or row <=0 or col <= 0:
			raise NameError('Initialization Fail')
		# member variable assign
		self.row = row
		self.col = col
		self.val = []
		for i in range(row):
			self.val.append([])
			for j in range(col):
				self.val[i].append(val[col*i+j])

	def __str__(self): # Make myMatrix to string value for scoring
		return str(self.val)

############ DO NOT change the above lines ############

	def addScalar(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] + op.val
		return res##행렬+스칼라
	def addMatrix(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] +op.val[i][j]
		return res##행렬+행렬
	def subScalar(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] - op.val
		return res##행렬-스칼라
	def subMatrix(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] -op.val[i][j]
		return res##행렬-행렬
	def mulScalar(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] *op.val
		return res##행렬*스칼라,또는 스칼라*행렬
	def mulMatrix(self,op):
		res = myMatrix(self.row,op.col)
		for i in range(res.row):
			for j in range(res.col):
				for k in range(self.col):
					res.val[i][j]+=self.val[i][k]*op.val[k][j]
		return res##행렬*행렬

	def divScalar(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] /op.val
		return res##행렬/스칼라


	def __add__(self, op):
		if type(op) is myScalar.myScalar:
			return self.addScalar(op)
		elif type(op) is myMatrix:
			if self.row!= op.row or self.col!=op.col:
				raise NameError('Dimension mismatch')##행렬 사이즈 불일치시 error
			else:
				return self.addMatrix(op)
		else:
			raise NameError('Not defined')

	def __sub__(self, op):
		if type(op) is myScalar.myScalar:
			return self.subScalar(op)
		elif type(op) is myMatrix:
			if self.row!= op.row or self.col!=op.col:
				raise NameError('Dimension mismatch')##행렬 사이즈 불일치시 error
			else:
				return self.subMatrix(op)
		else:
			raise NameError('Not defined')

	def __mul__(self,op):
		if type(op) is myScalar.myScalar:
			return self.mulScalar(op)
		elif type(op) is myMatrix:
			if self.col == op.row:
				return self.mulMatrix(op)
			else:
				raise NameError('Dimension mismatch')##피연산자1의 col과 피연산자2의 row가 일치하지 않을 시 error
		else:
			raise NameError('Not defined')
	def __truediv__(self,op):
		if type(op) is myScalar.myScalar:
			return self.divScalar(op)
		else:
			raise NameError('Not defined')
