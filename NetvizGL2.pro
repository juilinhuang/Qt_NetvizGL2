#-------------------------------------------------
#
# Project created by QtCreator 2017-06-02T13:12:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetvizGL2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    src/Graphs/AdjacencyGraph.cpp \
    src/Graphs/EdgeGraph.cpp \
    src/Graphs/Graph.cpp \
    src/Graphs/MatrixMarketGraph.cpp \
    src/Graphs/mmio.c \
    src/Algorithms/FruchtermanReingold.cpp \
    src/Algorithms/MultiForce.cpp \
    src/Algorithms/SimpleForceDirected.cpp \
    src/vertex.cpp \
    src/edge.cpp \
    src/Centrality/Betweenness.cpp \
    src/Centrality/DegreeCentrality.cpp \
    src/Centrality/DistanceCentrality.cpp \
    testthread.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    inc/Graphs/AdjacencyGraph.h \
    inc/Graphs/EdgeGraph.h \
    inc/Graphs/Graph.h \
    inc/Graphs/MatrixMarketGraph.h \
    inc/Graphs/mmio.h \
    inc/Algorithms/Algorithm.h \
    inc/Algorithms/FruchtermanReingold.h \
    inc/Algorithms/MultiForce.h \
    inc/Algorithms/SimpleForceDirected.h \
    inc/edge.h \
    inc/vertex.h \
    inc/Centrality/Betweenness.h \
    inc/Centrality/Centrality.h \
    inc/Centrality/DegreeCentrality.h \
    inc/Centrality/DistanceCentrality.h \
    inc/SimpleSvg.h \
    inc/SvgPrinter.h \
    testthread.h \
    inc/Command/Command.h \
    inc/Command/LoadGraph.h \
    inc/Command/SelectVertex.h \
    inc/Command/glwindow.h \
    inc/Command/DragVertex.h \
    inc/Command/DeleteVertex.h

FORMS    += mainwindow.ui

LIBS += -lOpengl32 -lGLU32

DISTFILES += \
    Graphs/nice.svg \
    Graphs/wow.svg \
    Graphs/Adjacency/adjacencymatrix.txt \
    Graphs/Adjacency/deletedAdj \
    Graphs/Adjacency/sirpenski5.txt \
    Graphs/Adjacency/test \
    Graphs/Adjacency/tree2500.txt \
    Graphs/EdgeLinks/ash85.txt \
    Graphs/EdgeLinks/betweenness.txt \
    Graphs/EdgeLinks/degreetest.txt \
    Graphs/EdgeLinks/edge-links.txt \
    Graphs/EdgeLinks/edge-links2.txt \
    Graphs/EdgeLinks/graph.txt \
    Graphs/EdgeLinks/MultiLevelTest.edg \
    Graphs/EdgeLinks/smallertest.txt \
    Graphs/EdgeLinks/testCentrality \
    Graphs/EdgeLinks/WilsGraph \
    Graphs/zero \
    Graphs/MatrixMarket/bcspwr03/bcspwr03.mtx \
    Graphs/MatrixMarket/can_229/can_229.mtx \
    Graphs/MatrixMarket/can_24/can_24.mtx \
    Graphs/MatrixMarket/can_96/can_96.mtx \
    Graphs/MatrixMarket/dwt_1007/dwt_1007.mtx \
    Graphs/MatrixMarket/dwt_918/dwt_918.mtx \
    Graphs/MatrixMarket/jagmesh4/jagmesh4.mtx \
    Graphs/MatrixMarket/ash85.mtx

