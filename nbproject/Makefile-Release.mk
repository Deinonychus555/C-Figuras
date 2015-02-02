#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/area.o \
	${OBJECTDIR}/dibujo.o \
	${OBJECTDIR}/exceptionRgb.o \
	${OBJECTDIR}/factoriaFigura.o \
	${OBJECTDIR}/factoriaFiguraInicializacion.o \
	${OBJECTDIR}/factoriaRectangulo.o \
	${OBJECTDIR}/factoriaSegmento.o \
	${OBJECTDIR}/factoriaTriangulo.o \
	${OBJECTDIR}/figura.o \
	${OBJECTDIR}/grupo.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/matriz.o \
	${OBJECTDIR}/punto.o \
	${OBJECTDIR}/rectangulo.o \
	${OBJECTDIR}/rgb.o \
	${OBJECTDIR}/segmento.o \
	${OBJECTDIR}/triangulo.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c__figuras

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c__figuras: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c__figuras ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/area.o: area.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/area.o area.cpp

${OBJECTDIR}/dibujo.o: dibujo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dibujo.o dibujo.cpp

${OBJECTDIR}/exceptionRgb.o: exceptionRgb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exceptionRgb.o exceptionRgb.cpp

${OBJECTDIR}/factoriaFigura.o: factoriaFigura.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factoriaFigura.o factoriaFigura.cpp

${OBJECTDIR}/factoriaFiguraInicializacion.o: factoriaFiguraInicializacion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factoriaFiguraInicializacion.o factoriaFiguraInicializacion.cpp

${OBJECTDIR}/factoriaRectangulo.o: factoriaRectangulo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factoriaRectangulo.o factoriaRectangulo.cpp

${OBJECTDIR}/factoriaSegmento.o: factoriaSegmento.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factoriaSegmento.o factoriaSegmento.cpp

${OBJECTDIR}/factoriaTriangulo.o: factoriaTriangulo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/factoriaTriangulo.o factoriaTriangulo.cpp

${OBJECTDIR}/figura.o: figura.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/figura.o figura.cpp

${OBJECTDIR}/grupo.o: grupo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/grupo.o grupo.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/matriz.o: matriz.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/matriz.o matriz.cpp

${OBJECTDIR}/punto.o: punto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/punto.o punto.cpp

${OBJECTDIR}/rectangulo.o: rectangulo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rectangulo.o rectangulo.cpp

${OBJECTDIR}/rgb.o: rgb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rgb.o rgb.cpp

${OBJECTDIR}/segmento.o: segmento.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/segmento.o segmento.cpp

${OBJECTDIR}/triangulo.o: triangulo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangulo.o triangulo.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c__figuras

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
