cmake_minimum_required(VERSION 3.10.0)
project(wxTimer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (DEFINED CLANG_GCC_TOOLCHAIN_PATH)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --gcc-toolchain=${CLANG_GCC_TOOLCHAIN_PATH}")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --gcc-toolchain=${CLANG_GCC_TOOLCHAIN_PATH}")
    endif()
    if(DEFINED CLANG_CXX_COMPILER_FLAGS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_CXX_COMPILER_FLAGS}")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	if(DEFINED GCC_CXX_COMPILER_FLAGS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_CXX_COMPILER_FLAGS}")
    endif()
endif()

find_package(wxWidgets REQUIRED COMPONENTS core base media)
include(${wxWidgets_USE_FILE})

include_directories(${wxWidgets_INCLUDE_DIRS})
link_directories(${wxWidgets_LIBRARY_DIRS})

add_executable(wxTimer
    main.cpp
    WxTimerFrame.cpp
    ObserverCreationPanel.cpp
    DialogAddEditTimer.cpp
    wxTimerFrameBase.cpp
    wxDialogAddEditTimerBase.cpp
    wxObserverCreationPanelBase.cpp
    FileExtensionList.cpp
    TimerBase.cpp
    CountdownTimer.cpp
    StopwatchTable.cpp
    TimerTable.cpp
    AudioPlaybackObserver.cpp
    NothingObserver.cpp
)

target_link_libraries(wxTimer ${wxWidgets_LIBRARIES})
