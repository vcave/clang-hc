//===--- FrontendOptions.cpp ----------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "clang/Frontend/FrontendOptions.h"
#include "llvm/ADT/StringSwitch.h"
using namespace clang;

//HC add input kind for HC
InputKind FrontendOptions::getInputKindForExtension(StringRef Extension) {
  return llvm::StringSwitch<InputKind>(Extension)
    .Cases("ast", "pcm", IK_AST)
    .Case("c", IK_C)
    .Cases("S", "s", IK_Asm)
    .Case("i", IK_PreprocessedC)
    .Case("ii", IK_PreprocessedCXX)
    .Case("m", IK_ObjC)
    .Case("mi", IK_PreprocessedObjC)
    .Cases("mm", "M", IK_ObjCXX)
    .Case("mii", IK_PreprocessedObjCXX)
    .Cases("C", "cc", "cp", IK_CXX)
    .Cases("cpp", "CPP", "c++", "cxx", "hpp", IK_CXX)
    .Case("cl", IK_OpenCL)
    .Case("cu", IK_CUDA)
    .Case("hc", IK_HC)
    .Cases("ll", "bc", IK_LLVM_IR)
    .Default(IK_C);
}
