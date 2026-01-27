import sys
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Simple Example')
        self.setGeometry(100, 100, 300, 200)  # (x, y, width, height)

        button = QPushButton('Click Me', self)
        button.move(100, 100)
        button.clicked.connect(self.on_button_click)

    def on_button_click(self):
        print('Button clicked!')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())