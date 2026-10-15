.RECIPEPREFIX=:
TRASH = *.o *~ *.out range log.txt

range: range.c
:	gcc -O0 -g range.c -o range

clean:
:       rm -f $(TRASH)

test: range
:       gdb --batch --command="1_12.gdb" ./range | grep '^@' > log.txt
:       gdb --batch --command="100.gdb" ./range | grep '^@' >> log.txt
:       cmp log.txt test.txt
