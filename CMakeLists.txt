cmake_minimum_required(VERSION 3.10)
project(ETicaretSiparis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/entities
    ${CMAKE_SOURCE_DIR}/include/services
    ${CMAKE_SOURCE_DIR}/include/repositories
    ${CMAKE_SOURCE_DIR}/include/utils
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/entities
    ${CMAKE_SOURCE_DIR}/src/services
    ${CMAKE_SOURCE_DIR}/src/repositories
    ${CMAKE_SOURCE_DIR}/src/utils
)

set(ENTITY_SOURCES
    src/entities/musteri.cpp
    src/entities/adres.cpp
    src/entities/kategori.cpp
    src/entities/urun.cpp
    src/entities/siparis.cpp
    src/entities/siparisKalemi.cpp
    src/entities/odeme.cpp
)

set(SERVICE_SOURCES
    src/services/eticaretServisi.cpp
)

set(SOURCES
    src/main.cpp
    ${ENTITY_SOURCES}
    ${SERVICE_SOURCES}
)

add_executable(eticaret_siparis ${SOURCES})

target_compile_options(eticaret_siparis PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>   # GCC için
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic> # Clang için
    $<$<CXX_COMPILER_ID:MSVC>:/W4>                       # Visual Studio için
)