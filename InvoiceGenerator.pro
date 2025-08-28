QT       += core gui \
    printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DAL/contractordal.cpp \
    DAL/invoicedal.cpp \
    DAL/invoicepositiondal.cpp \
    DAL/productdal.cpp \
    Model/contractormodel.cpp \
    Model/invoicebodymodel.cpp \
    Model/positionmodel.cpp \
    Model/productmodel.cpp \
    Repository/contractorrepository.cpp \
    Repository/invoicerepository.cpp \
    Repository/positionrepository.cpp \
    Repository/productrepository.cpp \
    Service/contractorservice.cpp \
    Service/invoiceservice.cpp \
    Service/productservice.cpp \
    Workers/fileworker.cpp \
    Workers/pdfworker.cpp \
    contractorsview.cpp \
    dialogaddcontractor.cpp \
    dialogaddproduct.cpp \
    dialognewinvoice.cpp \
    dialognewinvoiceaddproduct.cpp \
    invoicedetailsview.cpp \
    invoiceview.cpp \
    main.cpp \
    mainwindow.cpp \
    productview.cpp

HEADERS += \
    DAL/contractordal.h \
    DAL/invoicedal.h \
    DAL/invoicepositiondal.h \
    DAL/productdal.h \
    Model/contractormodel.h \
    Model/invoicebodymodel.h \
    Model/positionmodel.h \
    Model/productmodel.h \
    Repository/contractorrepository.h \
    Repository/invoicerepository.h \
    Repository/positionrepository.h \
    Repository/productrepository.h \
    Service/contractorservice.h \
    Service/invoiceservice.h \
    Service/productservice.h \
    Workers/fileworker.h \
    Workers/pdfworker.h \
    contractorsview.h \
    dialogaddcontractor.h \
    dialogaddproduct.h \
    dialognewinvoice.h \
    dialognewinvoiceaddproduct.h \
    invoicedetailsview.h \
    invoiceview.h \
    mainwindow.h \
    productview.h

FORMS += \
    contractorsview.ui \
    dialogaddcontractor.ui \
    dialogaddproduct.ui \
    dialognewinvoice.ui \
    dialognewinvoiceaddproduct.ui \
    invoicedetailsview.ui \
    invoiceview.ui \
    mainwindow.ui \
    productview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README
