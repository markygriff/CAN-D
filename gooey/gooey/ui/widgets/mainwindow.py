# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'qtdesigner/mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

import ui.widgets.resources
from PyQt5 import QtCore, QtGui, QtWidgets
from ui.widgets.rxtx import RxTxTab
from ui.widgets.trace import TraceTab
from ui.widgets.connection import ConnectionsTab


class CAND_MainWindow(object):
    def __init__(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1280, 778)
        MainWindow.setAutoFillBackground(False)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(90, 10, 1181, 741))
        self.tabWidget.setTabPosition(QtWidgets.QTabWidget.North)
        self.tabWidget.setMovable(True)
        self.tabWidget.setObjectName("tabWidget")

        # Trace Tab
        self.traceTab = QtWidgets.QWidget()
        TraceTab(self.traceTab)
        self.traceTab.setObjectName("traceTab")
        self.tabWidget.addTab(self.traceTab, "")

        # Receive/Transmit Tab
        self.rxtxTab = QtWidgets.QWidget()
        # Put rxtx component into tab
        RxTxTab(self.rxtxTab)
        self.rxtxTab.setObjectName("rxtxTab")
        self.tabWidget.addTab(self.rxtxTab, "")

        # Connections Tab
        self.connectionTab = QtWidgets.QWidget()
        ConnectionsTab(self.connectionTab)
        self.tabWidget.addTab(self.connectionTab, "Connections")

        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(0, 20, 82, 731))
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.layoutWidget.sizePolicy().hasHeightForWidth())
        self.layoutWidget.setSizePolicy(sizePolicy)
        self.layoutWidget.setObjectName("layoutWidget")
        self.sideBarLayout = QtWidgets.QVBoxLayout(self.layoutWidget)
        self.sideBarLayout.setSizeConstraint(QtWidgets.QLayout.SetMaximumSize)
        self.sideBarLayout.setContentsMargins(0, 0, 0, 0)
        self.sideBarLayout.setObjectName("sideBarLayout")
        self.openButton = QtWidgets.QToolButton(self.layoutWidget)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.openButton.sizePolicy().hasHeightForWidth())
        self.openButton.setSizePolicy(sizePolicy)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/icons/open.svg"),
                       QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.openButton.setIcon(icon)
        self.openButton.setIconSize(QtCore.QSize(70, 70))
        self.openButton.setObjectName("openButton")
        self.sideBarLayout.addWidget(self.openButton)
        self.saveButton = QtWidgets.QToolButton(self.layoutWidget)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.saveButton.sizePolicy().hasHeightForWidth())
        self.saveButton.setSizePolicy(sizePolicy)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/icons/save.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.saveButton.setIcon(icon1)
        self.saveButton.setIconSize(QtCore.QSize(70, 70))
        self.saveButton.setObjectName("saveButton")
        self.sideBarLayout.addWidget(self.saveButton)
        self.connectButton = QtWidgets.QToolButton(self.layoutWidget)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.connectButton.sizePolicy().hasHeightForWidth())
        self.connectButton.setSizePolicy(sizePolicy)
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(":/icons/connect.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.connectButton.setIcon(icon2)
        self.connectButton.setIconSize(QtCore.QSize(70, 70))
        self.connectButton.setObjectName("connectButton")
        self.sideBarLayout.addWidget(self.connectButton)
        self.disconnectButton = QtWidgets.QToolButton(self.layoutWidget)
        self.disconnectButton.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.disconnectButton.sizePolicy().hasHeightForWidth())
        self.disconnectButton.setSizePolicy(sizePolicy)
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(":/icons/disconnect.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.disconnectButton.setIcon(icon3)
        self.disconnectButton.setIconSize(QtCore.QSize(70, 70))
        self.disconnectButton.setObjectName("disconnectButton")
        self.sideBarLayout.addWidget(self.disconnectButton)
        self.recordButton = QtWidgets.QToolButton(self.layoutWidget)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.recordButton.sizePolicy().hasHeightForWidth())
        self.recordButton.setSizePolicy(sizePolicy)
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap(":/icons/record.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.recordButton.setIcon(icon4)
        self.recordButton.setIconSize(QtCore.QSize(70, 70))
        self.recordButton.setObjectName("recordButton")
        self.sideBarLayout.addWidget(self.recordButton)
        self.stopButton = QtWidgets.QToolButton(self.layoutWidget)
        self.stopButton.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.stopButton.sizePolicy().hasHeightForWidth())
        self.stopButton.setSizePolicy(sizePolicy)
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap(":/icons/stop.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.stopButton.setIcon(icon5)
        self.stopButton.setIconSize(QtCore.QSize(70, 70))
        self.stopButton.setObjectName("stopButton")
        self.sideBarLayout.addWidget(self.stopButton)
        self.playButton = QtWidgets.QToolButton(self.layoutWidget)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.playButton.sizePolicy().hasHeightForWidth())
        self.playButton.setSizePolicy(sizePolicy)
        icon6 = QtGui.QIcon()
        icon6.addPixmap(QtGui.QPixmap(":/icons/play.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.playButton.setIcon(icon6)
        self.playButton.setIconSize(QtCore.QSize(70, 70))
        self.playButton.setObjectName("playButton")
        self.sideBarLayout.addWidget(self.playButton)
        self.pauseButton = QtWidgets.QToolButton(self.layoutWidget)
        self.pauseButton.setEnabled(False)
        sizePolicy = QtWidgets.QSizePolicy(
            QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.pauseButton.sizePolicy().hasHeightForWidth())
        self.pauseButton.setSizePolicy(sizePolicy)
        icon7 = QtGui.QIcon()
        icon7.addPixmap(QtGui.QPixmap(":/icons/pause.svg"),
                        QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pauseButton.setIcon(icon7)
        self.pauseButton.setIconSize(QtCore.QSize(70, 70))
        self.pauseButton.setObjectName("pauseButton")
        self.sideBarLayout.addWidget(self.pauseButton)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1280, 22))
        self.menubar.setObjectName("menubar")
        self.menuCAN_D = QtWidgets.QMenu(self.menubar)
        self.menuCAN_D.setObjectName("menuCAN_D")
        self.menuFile = QtWidgets.QMenu(self.menuCAN_D)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionFile_2 = QtWidgets.QAction(MainWindow)
        self.actionFile_2.setObjectName("actionFile_2")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionSave_As = QtWidgets.QAction(MainWindow)
        self.actionSave_As.setObjectName("actionSave_As")
        self.menuFile.addAction(self.actionFile_2)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionSave_As)
        self.menuCAN_D.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuCAN_D.menuAction())

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate(
            "MainWindow", "CAN-D Data Logger"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(
            self.traceTab), _translate("MainWindow", "Trace"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(
            self.rxtxTab), _translate("MainWindow", "Receive/Transmit"))
        self.saveButton.setText(_translate("MainWindow", "..."))
        self.connectButton.setText(_translate("MainWindow", "..."))
        self.disconnectButton.setText(_translate("MainWindow", "..."))
        self.recordButton.setText(_translate("MainWindow", "..."))
        self.stopButton.setText(_translate("MainWindow", "..."))
        self.playButton.setText(_translate("MainWindow", "..."))
        self.pauseButton.setText(_translate("MainWindow", "..."))
        self.menuCAN_D.setTitle(_translate("MainWindow", "CAN-D"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.actionFile_2.setText(_translate("MainWindow", "Open..."))
        self.actionSave.setText(_translate("MainWindow", "Save"))
        self.actionSave_As.setText(_translate("MainWindow", "Save As ..."))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = CAND_MainWindow(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
