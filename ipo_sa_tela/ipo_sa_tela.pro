#-------------------------------------------------
#
# Project created by QtCreator 2013-12-27T17:12:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ipo_sa_tela
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    src/domain/alocacaoSala/Turma.cpp \
    src/domain/alocacaoSala/Sala.cpp \
    src/domain/SolucaoSa.cpp \
    src/controller/MainController.cpp \
    src/sa/ISimulatedAnneling.cpp \
    src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.cpp \
    src/sa/factory/ISimulatedAnnelingFactory.cpp \
    src/sa/factory/SimulatedAnnelingFactory.cpp \
    src/sa/parser/IParserSimulatedAnneling.cpp \
    src/sa/parser/alocacaoSala/IParserSimulatedAnnelingAlocacaoSala.cpp \
    src/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivo.cpp

HEADERS  += MainWindow.h \
    src/domain/alocacaoSala/Turma.h \
    src/enum/DiaSemana.h \
    src/domain/alocacaoSala/Sala.h \
    src/domain/SolucaoSa.h \
    src/controller/MainController.h \
    src/sa/ISimulatedAnneling.h \
    src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h \
    src/enum/TipoSimulatedAnneling.h \
    src/sa/factory/ISimulatedAnnelingFactory.h \
    src/sa/factory/SimulatedAnnelingFactory.h \
    src/sa/parser/IParserSimulatedAnneling.h \
    src/sa/parser/alocacaoSala/IParserSimulatedAnnelingAlocacaoSala.h \
    src/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivo.h \
    srcTest/tests.h \
    srcTest/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivoTest.h \
    srcTest/sa/factory/SimulatedAnnelingFactoryTest.h

FORMS    += MainWindow.ui
