import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
		vbox = QtGui.QVBoxLayout()
		
		self.lbl = QtGui.QLabel('Hello')
		
		btn = QtGui.QPushButton('Click me')
		btn.clicked.connect(self.handleClicked)
		
		vbox.addWidget(self.lbl)
		vbox.addWidget(btn)
		
		self.setLayout(vbox)
		self.setGeometry(300, 300, 250, 150)
		self.setWindowTitle('My Form')
		self.show()
	
	def handleClicked(self):
		self.lbl.setText('Button Clicked!')

app = QtGui.QApplication(sys.argv)
mainWindow = MyForm()
status = app.exec_()
sys.exit(status)
