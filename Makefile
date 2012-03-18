#Set root path
ROOT_PATH = ../../../
include $(ROOT_PATH)/lib/make/Makefile.dep
include $(ROOT_PATH)/lib/make/Makefile.comm  

#Set module name & target name
LIB = libeffect_filter.a
OBJ += effect_filter.o
OBJ += lomo_effect_filter.o
OBJ += gray_effect_filter.o
OBJ += effect_filter_insta.o

#Dependent header files  
CFLAGS += -O3
CFLAGS += $(OPENCV_INC)
CFLAGS += $(ULLOG_INC)

#Dependent libraries  
LDFLAGS += $(OPENCV_LIB)
LDFLAGS += $(ULLOG_LIB)


#########################################################
# Definition below don't need to modify in most of time #
#########################################################
.PHONY : all clean output

all: $(LIB) output

$(LIB): $(OBJ)
	rm -f $@
	ar cr $@ $(OBJ)

%.o : %.cpp  
	$(CC) -c $(CFLAGS) -o $@ $<  

output :
	rm -rf ./output
	mkdir ./output
	mkdir ./output/lib
	cp $(LIB) ./output/lib
	mkdir ./output/include
	cp *.h ./output/include

clean:  
	rm -f $(LIB) *.o
	rm -rf ./output
