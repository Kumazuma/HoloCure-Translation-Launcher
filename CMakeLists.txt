cmake_minimum_required(VERSION 3.0.0)
project(holocure-translatiion-launcher VERSION 0.1.0)

find_package(wxWidgets 3.2 COMPONENTS core base net REQUIRED)

include(${wxWidgets_USE_FILE})

add_executable(holocure-translatiion-launcher WIN32 main.cpp my.rc)
set_property(TARGET holocure-translatiion-launcher PROPERTY CXX_STANDARD 14 REQUIRED)
target_link_libraries(holocure-translatiion-launcher PRIVATE ${wxWidgets_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(MSVC)
    target_compile_options(holocure-translatiion-launcher PRIVATE /utf-8)
endif()

if(MINGW)
    target_compile_definitions(holocure-translatiion-launcher PRIVATE -DwxUSE_DPI_AWARE_MANIFEST=2)
endif()
