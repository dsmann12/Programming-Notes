import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
		
		btn1 = QtGui.QPushButton('One')
		btn2 = QtGui.QPushButton('Two')
		btn3 = QtGui.QPushButton('Three')
		btn4 = QtGui.QPushButton('Four')
		btn5 = QtGui.QPushButton('Five')

		layout = QtGui.QVBoxLayout()
		layout.addWidget(btn1)
		layout.addWidget(btn2)
		layout.addWidget(btn3)
		layout.addWidget(btn4)
		layout.addWidget(btn5)

		self.setLayout(layout)

		self.setGeometry(300, 300, 10, 10)
		self.setWindowTitle('My Form')
		self.show()

app = QtGui.QApplication(sys.argv)
mainWnidow = MyForm()
status = app.exec_()
sys.exit(status)
