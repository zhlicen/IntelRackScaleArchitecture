SET(TARGET_LIB redfish)

SET(SRC_LIB msg_reg.c rf_event.c)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/include)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/include)

ADD_LIBRARY(${TARGET_LIB} SHARED ${SRC_LIB})

ADD_DEPENDENCIES(${TARGET_LIB} json libutils)
TARGET_LINK_LIBRARIES(${TARGET_LIB}  libutils.so -lm)

ADD_DEPENDENCIES(${TARGET} json libutils librmmcfg)
