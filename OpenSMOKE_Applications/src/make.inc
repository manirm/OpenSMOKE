############################################################################
#
#  Program:         OpenSMOKE
#
#  Module:          make.inc
#
#  Purpose:         Top-level Definitions
#
#  Creation date:   January 9 2010
#
############################################################################

#  Compiler:   intel || gnu

COMPILER_NAME  	      = gnu

BZZ_PATH 	       =  ${HOME}/NumericalLibraries/BzzMath6
OPENSMOKE_PATH         =  ../../../../../../OpenSMOKE/OpenSMOKE

#Paths 
NUMERICALRECIPES_PATH  =  ${HOME}/NumericalLibraries/NumericalRecipes
LIS_PATH               =  ${HOME}/NumericalLibraries/lis-1.2.62/lis-omp-complete
MUMPS_PATH             =  ${HOME}/NumericalLibraries/MUMPS/MUMPS_4.9.2_SEQ_MKL_PORD
METIS_PATH             =  ${HOME}/NumericalLibraries/metis-5.0.2
BLAS_PATH              =  #{HOME}/NumericalLibraries/GotoBLAS2

#Options
OPTIONS_INTEL   =  -O3 -DUSE_INTEL_MKL=0 -I/usr/include/x86_64-linux-gnu/c++/4.8
OPTIONS_GNU     =  -O3 -m64 -Wall -fexpensive-optimizations -funroll-loops -DUSE_INTEL_MKL=0	

# ------------------------------------------------------------------------------------------------
# LIBRARY NAMES
# ------------------------------------------------------------------------------------------------

#BzzMath Libraries
BZZ_LIBS_INTEL  = -lBzzMath6_INTEL
BZZ_LIBS_GNU    = -lBzzMath6_GNU

#NR libraries
NR_LIBS_INTEL   =  -lNumericalRecipes_INTEL   
NR_LIBS_GNU     =  -lNumericalRecipes_GNU

#MUMPS libraries
MUMPS_LIBS      = -ldmumps -lmumps_common -lpord $(MUMPS_PATH)/libseq/libmpiseq.a 
LIS_LIBS        = -llis
METIS_LIBS      = -lmetis
BLAS_LIBS       = 

# ------------------------------------------------------------------------------------------------
# COMPILERS
# ------------------------------------------------------------------------------------------------
ifeq ($(COMPILER_NAME),intel)

OBJ_PATH    = intel
STRING_NAME = INTEL
CXX         = icpc
CXX_FLAGS   = $(OPTIONS_INTEL) -static
BZZ_LIBS    = $(BZZ_LIBS_INTEL)
NR_LIBS     = $(NR_LIBS_INTEL)
endif	

ifeq ($(COMPILER_NAME),gnu)

OBJ_PATH    = gnu
STRING_NAME = GNU
CXX         = g++
CXX_FLAGS   = $(OPTIONS_GNU) -static
BZZ_LIBS    = $(BZZ_LIBS_GNU) 
NR_LIBS     = $(NR_LIBS_GNU)
endif	

# ------------------------------------------------------------------------------------------------
# INCLUDE
# ------------------------------------------------------------------------------------------------
BZZ_INCLUDE          = -I$(BZZ_PATH)/hpp
MKL_INCLUDE          = -I$(MKL_PATH)/include
MKL_ROOT	     = ${MKL_PATH}
NR_INCLUDE           = -I$(NUMERICALRECIPES_PATH)/hpp
OPENSMOKE_INCLUDE    = -I$(OPENSMOKE_PATH)/hpp
MUMPS_INCLUDE        = -I$(MUMPS_PATH)/include
LIS_INCLUDE          = -I$(LIS_PATH)/include
METIS_INCLUDE        = -I$(METIS_PATH)/include

# ------------------------------------------------------------------------------------------------
# LIBRARY PATHS
# ------------------------------------------------------------------------------------------------
BZZ_PATH_LIB           = $(BZZ_PATH)/lib/release
NR_PATH_LIB            = $(NUMERICALRECIPES_PATH)/lib/release
OPENSMOKE_PATH_LIB     = $(OPENSMOKE_PATH)/lib/linux/$(OBJ_PATH)
MKL_PATH_LIB           = $(MKL_PATH)/lib/intel64
MUMPS_PATH_LIB         = $(MUMPS_PATH)/lib
LIS_PATH_LIB           = $(LIS_PATH)/lib
METIS_PATH_LIB         = $(METIS_PATH)/lib
BLAS_PATH_LIB          = $(BLAS_PATH)

MKL_LIBS               =

 


 




