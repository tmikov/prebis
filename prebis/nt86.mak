OUT=out

CC=cl
BSC=bscmake

CDEFINES=-DUSE_GC
CFLAGS=-W3 -I.. -I. -Fr$(OUT)\\

!IFDEF debug 
CDEFINES=$(CDEFINES) -D_DEBUG -DYYDEBUG=1
CFLAGS=$(CFLAGS) -MDd -Zi 
!ELSE
CFLAGS=$(CFLAGS) -MD -O1
!ENDIF

CFLAGS=$(CFLAGS) $(CDEFINES)

BISON=bison
BFLAGS=-v --skeleton=main/bison.simple.c

FLEX=flex
FFLAGS=-b -p -f

M4=m4
M4FLAGS=

REPL=..\utils\repl\repl.exe

TGT=i386

FILES=

##############################################################

all: $(OUT)\prebis.bsc $(OUT)\prebis.exe

clean:
  @del *.pdb;*.pch;*.ilk;*.obj;*.exe;*.sbr;*.bsc /s
  @del main\pre.output

##############################################################
#
# ulib\c
#
##############################################################
FILES=$(FILES)\
  $(OUT)\debug.obj        \
  $(OUT)\cord.obj         \
  $(OUT)\clist.obj        \
  $(OUT)\simgc.obj        \
  $(OUT)\strings.obj

{..\ulib\c}.c{$(OUT)}.obj::
  $(CC) $(CFLAGS) -I..\ulib\h -Fo$(OUT)\ -c $<

##############################################################
#
# ulib\avl-0.4
#
##############################################################
FILES=$(FILES)\
  $(OUT)\avl.obj

{..\ulib\avl-0.4}.c{$(OUT)}.obj::
  $(CC) $(CFLAGS) -Fo$(OUT)\ -c $<

##############################################################
#
# prebis
#
##############################################################
FILES=$(FILES)\
  $(OUT)\prebis.obj  \
  $(OUT)\lex.yy.obj  \
  $(OUT)\pre.tab.obj \
  $(OUT)\idtab.obj   \
  $(OUT)\gen.obj

{main}.c{$(OUT)}.obj::
  $(CC) $(CFLAGS) -Fo$(OUT)\ -c $<

main\lex.yy.c: main\pre.tab.h main\scan.l
  $(FLEX) $(FFLAGS) -omain/lex.yy.c main/scan.l

main\pre.tab.inc: main\pre.yp
  out\prebis -t $** > main/pre1.y
  $(BISON) --token-table --no-parser -o main/pre1.tab.c main/pre1.y
  cl -DYYACT=\"pre1.act\" -Femain/pre1.tab.exe main/pre1.tab.c
  main\pre1.tab.exe > $@


main\pre.y: main\pre.yp
  out\prebis main\pre.yp > main\pre.y

main\pre.tab.h: main\pre.y

main\pre.tab.c: main\pre.y main\pre.tab.inc 
  $(BISON) $(BFLAGS) -d -o main/pre.tab.c main/pre.y
  $(REPL) $@ pre.y pre.yp

$(OUT)\prebis.exe: $(FILES)
  cl $(CFLAGS) -Fe$@ $** 

$(OUT)\prebis.bsc: $(FILES)
  $(BSC) -o $@ $(OUT)\*.sbr
