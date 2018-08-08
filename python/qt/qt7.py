import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
		
		first = QtGui.QLineEdit()
 		last = QtGui.QLineEdit()
 		gender = QtGui.QComboBox()
 		gender.addItems(['Mail', 'Female'])
		age = QtGui.QSpinBox()
		age.setMinimum(18)
		
		mainLayout = QtGui.QFormLayout()
		
		mainLayout.addRow('First', first)
		mainLayout.addRow('Last', last)
		mainLayout.addRow('Gender', gender)
		mainLayout.addRow('Age:', age)

		self.setLayout(mainLayout)

		self.setGeometry(300, 300, 10, 10)
		self.setWindowTitle('My Form')
		self.show()

app = QtGui.QApplication(sys.argv)
mainWindow = MyForm()
status = app.exec_()
sys.exit(status)

