import myString
import myMatrix

class myScalar:

	def __init__(self, val):
		# check the input parameter
		if type(val)!=float:
			raise NameError('Initialization Fail')
		# member variable assign
		self.val = val

	def __str__(self): # Make myScalar to string value for scoring
		return str(self.val)

############ do not change the above lines ############

	def addStr(self,op):
		res = myString.myString('')
		return myString.myString(str(self.val)+op.val)

	def subMatrix(self,op):
		res = myMatrix.myMatrix(op.row,op.col)
		for i in range(len(op.val)):
			for j in range(len(op.val[i])):
				res.val[i][j] = self.val - op.val[i][j]
		return res## 스칼라 - 행렬의 경우
	def mulString(self,op):
		res = myString.myString('')
		if self.val>0:
			for i in range(int(self.val)):
				res.val+=op.val
		elif self.val<0:
			for i in range(int(self.val)*(-1)):
				temp = ''.join(reversed(op.val))
				res.val+=temp
		elif self.val==0:
			return
		return res##스칼라*문자열의 경우, float형을 int로 바꾸어 정수부분만 얻고, 이것이 양수면 for문을 사용하여 n번 더하고, 이것이 음수면 먼저 역순으로 바꾸고, 그것을 n번 더했다. 만약 0이라면, return None을 하였다.


	def __add__(self, op):
		if type(op) is myScalar:
			return myScalar(self.val+op.val)
		elif type(op) is myMatrix.myMatrix:
			return (op + self)
		elif type(op) is myString.myString:
			return self.addStr(op)
		else:
			raise NameError('Not defined')
	
	def __sub__(self,op):
		if type(op) is myScalar:
			return myScalar(self.val-op.val)
		elif type(op) is myMatrix.myMatrix:
			return self.subMatrix(op)
		else:
			raise NameError('Not defined')

	def __mul__(self,op):
		if type(op) is myScalar:
			return myScalar(self.val*op.val)
		elif type(op) is myMatrix.myMatrix:
			return (op*self)
		elif type(op) is myString.myString:
			return self.mulString(op)
		else:
			raise NameError('Not defined')

	def __truediv__(self,op):
		if type(op) is myScalar:
			return myScalar(self.val/op.val)
		else:
			raise NameError('Not defined')

         ##따로 function을 정의하지 않고 return선에서 처리할 수 있는 것은 그리하였다.           




