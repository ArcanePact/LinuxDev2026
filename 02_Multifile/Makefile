.RECIPEPREFIX=:
GENERATES = prog README liboutput.so prog-a prog-so
TRASH = *.o *~ o.* *.a *.txt

all:    README prog liboutput_static.a liboutput.so prog-a prog-so

%.o: %.c
:       cc -fPIC $< -c -o $@

prog:   const.o fun.o prog.o

README: prog
:       ./$< 2> $@

liboutput_static.a: const.o fun.o
:       ar -rcs $@ $^

liboutput.so: const.o fun.o
:       cc -shared $^ -o $@

prog-a: prog.o liboutput_static.a
:       cc -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
:       cc -L. $< -loutput -o $@

fun.o:  outlib.h

clean:
:       rm -f $(TRASH)

distclean:      clean
:       rm -rf $(GENERATES)

test: prog prog-a prog-so
:       ./prog > default_readme.txt 2>&1
:       ./prog-a > static_readme.txt 2>&1
:       LD_LIBRARY_PATH=`pwd` ./prog-so > dynamic_readme.txt 2>&1
:       ./prog uneex > default_onearg.txt 2>&1
:       ./prog-a uneex > static_onearg.txt 2>&1
:       LD_LIBRARY_PATH=`pwd` ./prog-so uneex > dynamic_onearg.txt 2>&1
:       ./prog uneex the best > default_threeargs.txt 2>&1
:       ./prog-a uneex the best > static_threeargs.txt 2>&1
:       LD_LIBRARY_PATH=`pwd` ./prog-so uneex the best > dynamic_threeargs.txt 2>&1
:       cmp default_readme.txt static_readme.txt
:       cmp default_readme.txt dynamic_readme.txt
:       cmp default_onearg.txt static_onearg.txt
:       cmp default_onearg.txt dynamic_onearg.txt
:       cmp default_threeargs.txt static_threeargs.txt
:       cmp default_threeargs.txt dynamic_threeargs.txt