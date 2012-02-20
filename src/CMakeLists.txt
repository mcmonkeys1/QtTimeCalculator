# Generic Qt4 for compiling sources from a single directory.
# Only the project name needs to be changed.
#
cmake_minimum_required (VERSION 2.8)
project (QtTimeCalculator) # <-Change to the name of your project.

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

file(GLOB ${PROJECT_NAME}_SOURCES *.cpp)
file(GLOB ${PROJECT_NAME}_HEADERS *.h)
file(GLOB ${PROJECT_NAME}_FORMS *.ui)
file(GLOB ${PROJECT_NAME}_RESOURCES resources.qrc)

qt4_wrap_cpp(${PROJECT_NAME}_HEADERS_MOC ${${PROJECT_NAME}_HEADERS})
qt4_wrap_ui(${PROJECT_NAME}_FORMS_UIC ${${PROJECT_NAME}_FORMS}) 
qt4_add_resources(${PROJECT_NAME}_RESOURCES_RCC ${${PROJECT_NAME}_RESOURCES})

source_group("Headers" FILES ${${PROJECT_NAME}_HEADERS})
source_group("Qt4 MetaObjectCompiler Files" FILES ${${PROJECT_NAME}_HEADERS_MOC})
source_group("Qt4 Forms" FILES ${${PROJECT_NAME}_FORMS} ${${PROJECT_NAME}_FORMS_UIC})
source_group("Qt4 Resources" FILES ${${PROJECT_NAME}_RESOURCES_RCC} ${${PROJECT_NAME}_RESOURCES})

#set(QT_USE_QTNETWORK, true)
#set(QT_USE_QTSQL, true)
#set(QT_USE_QTXML, true)
#set...etc go here


add_executable(${PROJECT_NAME} WIN32
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_HEADERS}
	${${PROJECT_NAME}_HEADERS_MOC}
	${${PROJECT_NAME}_FORMS_UIC}
	${${PROJECT_NAME}_RESOURCES_RCC}
	)

target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY})

