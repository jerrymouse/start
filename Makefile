AS      =as
LD      =ld
CC      =g++
AR      =ar



CFLAGS =  -g -Wall -pedantic #-std=c++0x
CFLAGS += 
LDFLAGS = 
SRCS	=  $(wildcard *.cpp)
#SRCS =  Palindrome.cpp longestCommonSubstring.cpp \
#		LongestPalindromicSubstring.cpp regularExpression.cpp \
#		cycleSortedList.cpp reverseBit.cpp lowestCommonAncestorBT.cpp \
#		maximizingDistance.cpp LSWithoutRepeatingCharacter.cpp \
#		PainterPartitionProblem.cpp CoinsInLine.cpp \
#		slidingWindowMaximum.cpp NutsinOasis.cpp \
#		StudiousStudentProblem.cpp DoubleSquareProblem.cpp \
#		sideEffect.cpp removeSpace.cpp countWords.cpp \
#		binary_tree_pretty_print.cpp shiftK.cpp sum.cpp max.cpp \
#		topK.cpp  test.cpp list.cpp recursionRescue.cpp add.cpp \
#		virtual.cpp  testMatrix.cpp matrixTransform.cpp delCopy.cpp \
#		test_unordermap.cpp shortest_move.cpp threeSum.cpp \
#		genNub_1G.cpp fileTopK.cpp test1.cpp regularEx.cpp \
#		atoi.cpp BinarySTTODoubleLinkedList.cpp \
#		arraycut.cpp numBytes.cpp chess.cpp RainTrap.cpp \
#		pow.cpp MatrixFindZero.cpp 2DRainWater.cpp
OBJS := $(SRCS:.cpp=.exe)


all: $(OBJS)

$(OBJS):%.exe:%.cpp	
	$(CC) -g -o $@ $< $(CFLAGS)
.SUFFIXES:
.SUFFIXES: .c .o
.PHONY:clean
clean: 
	$(RM) *.o 
	$(RM) ${OBJS}
