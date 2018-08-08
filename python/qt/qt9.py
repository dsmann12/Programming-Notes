import sys
from PyQt4 import QtGui

class MyForm(QtGui.QWidget):
	def __init__(self):
		super(MyForm, self).__init__()
		
		vbox = QtGui.QVBoxLayout()
		
		self.lblPressed = QtGui.QLabel('1')
		self.lblReleased = QtGui.QLabel('2')
		self.lblClicked = QtGui.QLabel('3')

		btn = QtGui.QPushButton('Click Me')
		btn.clicked.connect(self.handleClicked)
		btn.pressed.connect(self.handlePressed)
		btn.released.connect(self.handleReleased)

		vbox.addWidget(self.lblPressed)
		vbox.addWidget(self.lblReleased)
		vbox.addWidget(self.lblClicked)
		vbox.addWidget(btn)

		self.setLayout(vbox)
		self.setGeometry(300, 300, 250, 150)
		self.setWindowTitle('My Form')
		self.show()

	def handleClicked(self):
		self.lblClicked.setText('Clicked')

	def handlePressed(self):
		self.lblPressed.setText('Pressed')

	def handleReleased(self):
		self.lblReleased.setText('Released')

app = QtGui.QApplication(sys.argv)
mainWindow = MyForm()
status = app.exec_()
sys.exit(status)
