import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
	
		lbl1 = QtGui.QLabel('One')
		lbl2 = QtGui.QLabel('Two')
		lbl3 = QtGui.QLabel('Three')
		lbl4 = QtGui.QLabel('Four')
		lbl5 = QtGui.QLabel('Five')

		layout1 = QtGui.QVBoxLayout()
		layout1.addWidget(lbl1)
		layout1.addWidget(lbl2)
		layout1.addWidget(lbl3)
		layout1.addWidget(lbl4)
		layout1.addWidget(lbl5)
		
		btn1 = QtGui.QPushButton('One')
		btn2 = QtGui.QPushButton('Two')
		btn3 = QtGui.QPushButton('Three')
		btn4 = QtGui.QPushButton('Four')
		btn5 = QtGui.QPushButton('Five')

		layout2 = QtGui.QVBoxLayout()
		layout2.addWidget(btn1)
		layout2.addWidget(btn2)
		layout2.addWidget(btn3)
		layout2.addWidget(btn4)
		layout2.addWidget(btn5)

		mainLayout = QtGui.QHBoxLayout()
		mainLayout.addLayout(layout1)
		mainLayout.addLayout(layout2)

		self.setLayout(mainLayout)

		self.setGeometry(300, 300, 10, 10)
		self.setWindowTitle('My Form')
		self.show()

app = QtGui.QApplication(sys.argv)
mainWnidow = MyForm()
status = app.exec_()
sys.exit(status)
