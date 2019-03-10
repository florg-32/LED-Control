import sys

from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5 import uic
from serial import Serial

def by(n):
    return n.to_bytes(1, 'big')

s = Serial("COM3", 9600)
 
class MyApp(QMainWindow):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        uic.loadUi("qt.ui", self)

    def setColor(self):
        s.write(by(0))
        s.write(by(self.rSlider.value()))
        s.write(by(self.gSlider.value()))
        s.write(by(self.bSlider.value()))
 
if __name__ == "__main__":
    app = QApplication([])
    window = MyApp()
    window.show()
    sys.exit(app.exec_())