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
    src/controller/MainController.cpp \
    src/sa/ISimulatedAnneling.cpp \
    src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.cpp \
    src/sa/factory/ISimulatedAnnelingFactory.cpp \
    src/sa/factory/SimulatedAnnelingFactory.cpp \
    src/sa/parser/IParserSimulatedAnneling.cpp \
    src/sa/parser/alocacaoSala/IParserSimulatedAnnelingAlocacaoSala.cpp \
    src/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivo.cpp \
    src/domain/ISolucaoSa.cpp \
    src/domain/alocacaoSala/SolucaoSaAlocacaoSala.cpp \
    src/util/MathUtil.cpp \
    src/domain/alocacaoSala/SolucaoSaAlocacaoSalaCompleta.cpp

HEADERS  += MainWindow.h \
    src/domain/alocacaoSala/Turma.h \
    src/enum/DiaSemana.h \
    src/domain/alocacaoSala/Sala.h \
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
    srcTest/sa/factory/SimulatedAnnelingFactoryTest.h \
    srcTest/sa/factory/SimulatedAnnelingFactoryTest.h \
    src/domain/ISolucaoSa.h \
    src/domain/alocacaoSala/SolucaoSaAlocacaoSala.h \
    src/util/MathUtil.h \
    srcTest/sa/alocacaoSala/SimulatedAnnelingAlocacaoSalaTest.h \
    src/domain/functor/CapacidadeSalaFunctor.h \
    src/domain/functor/DemandaTurmaFunctor.h \
    srcTest/domain/functor/DemandaTurmaFunctorTest.h \
    srcTest/domain/functor/CapacidadeSalaFunctorTest.h \
    srcTest/util/MathUtilTest.h \
    srcTest/domain/alocacaoSala/SolucaoSaAlocacaoSalaTest.h \
    src/domain/alocacaoSala/SolucaoSaAlocacaoSalaCompleta.h \
    src/domain/functor/CodigoTurmaFunctor.h \
    srcTest/domain/functor/CodigoTurmaFunctorTest.h

FORMS    += MainWindow.ui
