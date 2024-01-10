TEMPLATE = app
CONFIG += console
#c++11
CONFIG -= app_bundle
#CONFIG -= qt

lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 5): CONFIG += c++11

SOURCES += main.cpp \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_valueiterator.inl \
    json/json_writer.cpp

HEADERS += \
    json/allocator.h \
    json/assertions.h \
    json/config.h \
    json/forwards.h \
    json/json.h \
    json/json_features.h \
    json/json_tool.h \
    json/reader.h \
    json/value.h \
    json/version.h \
    json/writer.h

DISTFILES +=

RESOURCES += \
    thb_model.qrc
