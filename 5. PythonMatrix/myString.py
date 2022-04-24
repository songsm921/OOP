import myScalar
import myMatrix

class myString:

	def __init__(self, val):
		# check the input parameter
		if type(val) != str:
			raise NameError('Initialization Fail')
		# member variable assign
		self.val = val
		
	def __str__(self): # Make myString to string value for scoring
		return self.val

############ do not change the above lines ############

	def mulScal(self,op):
		res = myString('')
		if op.val>0:
			for i in range(int(op.val)):
				res.val+=self.val
		elif op.val<0:
			for i in range(int(op.val)*(-1)):
				temp = ''.join(reversed(self.val))
				res.val+=temp
		elif op.val ==0:
			return
		return res##문자열*스칼라 방식은 스칼라*문자열과 같습니다.



	def __add__(self, op):
		if type(op) is myScalar.myScalar:
			return self.val+str(op.val)
		elif type(op) is myString:
			return self.val+op.val
		else:
			raise NameError('Not defined')

	def __sub__(self, op):
		raise NameError('Not defined')

	def __truediv__(self, op):
		raise NameError('Not defined')



	def __mul__(self,op):
		if type(op) is myScalar.myScalar:
			return self.mulScal(op)
		else:
			raise NameError('Not defined')
