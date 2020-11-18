cmake_minimum_required(VERSION 3.2)

set(TRAVIS_BUILD_NUMBER $ENV{TRAVIS_BUILD_NUMBER})
if(NOT TRAVIS_BUILD_NUMBER)
    set(TRAVIS_BUILD_NUMBER 1)
endif()

project(alloc VERSION 0.0.${TRAVIS_BUILD_NUMBER})

if (MSVC)
    set(COMPILE_OPTS /W4)
else ()
    set(COMPILE_OPTS -Wall -Wextra -pedantic -Werror)
endif()

add_executable(alloc src/main.cpp)

set(timus_executables)
foreach(task_number
        1264
        1409
        1787
        1877
        2001
        )
    add_executable(timus_${task_number} timus/${task_number}.cpp)
    target_compile_options(timus_${task_number} PRIVATE ${COMPILE_OPTS})
    list(APPEND timus_executables timus_${task_number})
endforeach(task_number)

set_target_properties(alloc ${timus_executables} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(alloc PRIVATE ${COMPILE_OPTS})

install(TARGETS alloc RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT mike.42.alexeev@yandex.ru)

include(CPack)
