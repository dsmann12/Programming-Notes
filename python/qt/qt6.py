import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
	
		lbl1 = QtGui.QLabel('First')
		lbl2 = QtGui.QLabel('Last')
		lbl3 = QtGui.QLabel('Gender')
		lbl4 = QtGui.QLabel('Age')
		first = QtGui.QLineEdit()
		last = QtGui.QLineEdit()
		gender = QtGui.QComboBox()
		gender.addItems(['Male', 'Female'])
		age = QtGui.QSpinBox()
		age.setMinimum(18)

		mainLayout = QtGui.QGridLayout()
		mainLayout.addWidget(lbl1, 0, 0)
		mainLayout.addWidget(lbl2, 1, 0)
		mainLayout.addWidget(lbl3, 2, 0)
		mainLayout.addWidget(lbl4, 3, 0)
		
		mainLayout.addWidget(first, 0, 1)
		mainLayout.addWidget(last, 1, 1)
		mainLayout.addWidget(gender, 2, 1)
		mainLayout.addWidget(age, 3, 1)

		self.setLayout(mainLayout)

		self.setGeometry(300, 300, 10, 10)
		self.setWindowTitle('My Form')
		self.show()

app = QtGui.QApplication(sys.argv)
mainWnidow = MyForm()
status = app.exec_()
sys.exit(status)
