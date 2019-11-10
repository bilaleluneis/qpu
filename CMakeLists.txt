cmake_minimum_required(VERSION 3.13)
project(qpu)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

option(QPU_MODE "RUN ON VPU/QPU/GPU" ON) # if set to off will run on emulation mode
option(DEBUG "ENABLE DEBUGGING LOGS" OFF)

add_compile_options(-Wconversion)
add_compile_options(-fpermissive)
add_compile_options(-std=c++0x)

if(QPU_MODE)
    add_compile_definitions(QPU_MODE)
endif()

if(DEBUG)
    add_compile_definitions(DEBUG)
endif()

add_executable(qpu main.cpp
        lib/Kernel.h lib/Kernel.cpp
        lib/Params.h
        lib/QPULib.h
        lib/VideoCore/VideoCore.h lib/VideoCore/VideoCore.cpp
        lib/VideoCore/SharedArray.h
        lib/VideoCore/Mailbox.h lib/VideoCore/Mailbox.cpp
        lib/VideoCore/Invoke.h lib/VideoCore/Invoke.cpp
        lib/Target/Syntax.h lib/Target/Syntax.cpp
        lib/Target/Subst.h lib/Target/Subst.cpp
        lib/Target/SmallLiteral.h lib/Target/SmallLiteral.cpp
        lib/Target/Satisfy.h lib/Target/Satisfy.cpp
        lib/Target/RemoveLabels.h lib/Target/RemoveLabels.cpp
        lib/Target/RegAlloc.h lib/Target/RegAlloc.cpp
        lib/Target/ReachingDefs.h lib/Target/ReachingDefs.cpp
        lib/Target/Pretty.h lib/Target/Pretty.cpp
        lib/Target/LoadStore.h lib/Target/LoadStore.cpp
        lib/Target/LiveRangeSplit.h lib/Target/LiveRangeSplit.cpp
        lib/Target/Liveness.h lib/Target/Liveness.cpp
        lib/Target/Encode.h lib/Target/Encode.cpp
        lib/Target/Emulator.h lib/Target/Emulator.cpp
        lib/Target/CFG.h lib/Target/CFG.cpp
        lib/Source/Translate.h lib/Source/Translate.cpp
        lib/Source/Syntax.h lib/Source/Syntax.cpp
        lib/Source/StmtExtra.h lib/Source/Stmt.h lib/Source/Stmt.cpp
        lib/Source/Ptr.h
        lib/Source/Pretty.h lib/Source/Pretty.cpp
        lib/Source/Interpreter.h lib/Source/Interpreter.cpp
        lib/Source/Int.h lib/Source/Int.cpp
        lib/Source/Gen.h lib/Source/Gen.cpp
        lib/Source/Float.h lib/Source/Float.cpp
        lib/Source/Cond.h
        lib/Common/Heap.h lib/Common/Seq.h lib/Common/Stack.h
        )
