# Makefile generated by OpenModelica
# Platform: win64

# Simulations use -O3 by default
CC=gcc
CXX=g++
LINK=g++ -shared -Xlinker --export-all-symbols -fPIC
EXEEXT=.exe
DLLEXT=.dll
CFLAGS_BASED_ON_INIT_FILE=
DEBUG_FLAGS=-Os
CFLAGS=$(CFLAGS_BASED_ON_INIT_FILE) $(DEBUG_FLAGS) -falign-functions -fno-ipa-pure-const -mstackrealign -msse2 -mfpmath=sse ${MODELICAUSERCFLAGS}   
CPPFLAGS= -I"C:/OpenModelica1.13.264bit//include/omc/c" -I. -DOPENMODELICA_XML_FROM_FILE_AT_RUNTIME -DOMC_MODEL_PREFIX=cooler1 -DOMC_NUM_MIXED_SYSTEMS=0 -DOMC_NUM_LINEAR_SYSTEMS=4 -DOMC_NUM_NONLINEAR_SYSTEMS=4 -DOMC_NDELAY_EXPRESSIONS=0 -DOMC_NVAR_STRING=0
LDFLAGS=-L"C:/OpenModelica1.13.264bit//lib//omc" -L"C:/OpenModelica1.13.264bit//lib" -Wl,--stack,16777216,-rpath,"C:/OpenModelica1.13.264bit//lib//omc" -Wl,-rpath,"C:/OpenModelica1.13.264bit//lib"   -fopenmp -Wl,-Bstatic -lregex -ltre -lintl -liconv -lexpat -lomcgc -lpthread -loleaut32 -limagehlp -lhdf5 -lz -lszip -Wl,-Bdynamic  -Wl,-Bstatic -lSimulationRuntimeC -Wl,-Bdynamic -Wl,-Bstatic -lomcgc -lregex -ltre -lintl -liconv -lexpat -static-libgcc -luuid -loleaut32 -lole32 -limagehlp -lws2_32 -llis -lumfpack -lklu -lcolamd -lbtf -lamd  -lsundials_idas -lsundials_kinsol -lsundials_nvecserial -lipopt -lcoinmumps -lpthread -lm -lgfortranbegin -lgfortran -lquadmath -lmingw32 -lgcc_eh -lmoldname -lmingwex -lmsvcrt -luser32 -lkernel32 -ladvapi32 -lshell32 -lopenblas -lcminpack -Wl,-Bdynamic -lwsock32 -Wl,-Bstatic -lstdc++ -Wl,-Bdynamic 
DIREXTRA=-L"C:/OMChemSimGUI/SimulationFiles/Simulator"
MAINFILE=cooler1.c
MAINOBJ=cooler1.o
CFILES=cooler1_functions.c cooler1_records.c \
cooler1_01exo.c cooler1_02nls.c cooler1_03lsy.c cooler1_04set.c cooler1_05evt.c cooler1_06inz.c cooler1_07dly.c \
cooler1_08bnd.c cooler1_09alg.c cooler1_10asr.c cooler1_11mix.c cooler1_12jac.c cooler1_13opt.c cooler1_14lnz.c \
cooler1_15syn.c cooler1_16dae.c cooler1_17inl.c 

OFILES=$(CFILES:.c=.o)
GENERATEDFILES=$(MAINFILE) cooler1.makefile cooler1_literals.h cooler1_functions.h $(CFILES)

.PHONY: omc_main_target clean bundle

# This is to make sure that cooler1_*.c are always compiled.
.PHONY: $(CFILES)

omc_main_target: $(MAINOBJ) cooler1_functions.h cooler1_literals.h $(OFILES)
	$(CC) -I. -o cooler1$(EXEEXT) $(MAINOBJ) $(OFILES) $(CPPFLAGS) $(DIREXTRA)   $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
clean:
	@rm -f cooler1_records.o $(MAINOBJ)

bundle:
	@tar -cvf cooler1_Files.tar $(GENERATEDFILES)