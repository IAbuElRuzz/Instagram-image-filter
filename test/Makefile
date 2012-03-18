#Set root path
ROOT_PATH = ../../../../
include $(ROOT_PATH)/lib/make/Makefile.dep
include $(ROOT_PATH)/lib/make/Makefile.comm  

#Set module name & target name
BIN = test_effect_filter
OBJ = test_effect_filter.o

#Dependent header files  
CFLAGS += $(OPENCV_INC)
CFLAGS += -I../output/include
CFLAGS += $(ULLOG_INC)

#Dependent libraries  
LDFLAGS += $(OPENCV_LIB)
LDFLAGS += -L../output/lib -leffect_filter
LDFLAGS += $(ULLOG_LIB)

#########################################################
# Definition below don't need to modify in most of time #
#########################################################
.PHONY : all clean

all: $(BIN) output
	rm -f *.o

$(BIN) : $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)   

%.o : %.cpp  
	$(CC) -c $(CFLAGS) -o $@ $<  

output :
	rm -rf ./output
	mkdir ./output
	cp $(BIN) ./output

clean:  
	rm -f $(BIN) *.o
	rm -rf ./output
