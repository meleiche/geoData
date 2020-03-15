#
# ---------------------------------------------------------
# make PROGRAM=xyz2llh
# ---------------------------------------------------------
SRC1      = ./
OBJ1      = ./
INC1      = ./
INC_DIR2 = .
EXE      = ./
$(EXE)xyz2llh : \
$(OBJ1)plh2xyz.o \
$(OBJ1)xyz2llh.o \
$(OBJ1)xyz2plh.o \
$(OBJ1)degdms.o
	cc -g -o $(EXE)xyz2llh \
	$(OBJ1)xyz2llh.o \
	$(OBJ1)plh2xyz.o \
	$(OBJ1)xyz2plh.o \
	$(OBJ1)degdms.o \
	-lm
$(OBJ1)xyz2llh.o :$(SRC1)xyz2llh.c
	cc -c -g -I$(INC_DIR1) -I$(INC_DIR2) $(SRC1)xyz2llh.c -o $(OBJ1)xyz2llh.o
$(OBJ1)plh2xyz.o :$(SRC1)plh2xyz.c
	cc -c -I$(INC_DIR1) -I$(INC_DIR2) $(SRC1)plh2xyz.c -o $(OBJ1)plh2xyz.o
$(OBJ1)xyz2plh.o :$(SRC1)xyz2plh.c
	cc -c -I$(INC_DIR1) -I$(INC_DIR2) $(SRC1)xyz2plh.c -o $(OBJ1)xyz2plh.o
$(OBJ1)degdms.o :$(SRC1)degdms.c
	cc -c -I$(INC_DIR1) -I$(INC_DIR2) $(SRC1)degdms.c -o $(OBJ1)degdms.o
