set pagination off

b 27 if i % 5 == 0
command 1
silent
printf "@ begin= %d, end= %d, step= %d, i= %d\n", begin, end, step, i
cont
end

run 1 12 > /dev/null
quit
