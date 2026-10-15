set pagination off
set $cnt = 0

b 27
command 1
silent
set $cnt = $cnt + 1 
if $cnt > 27 && $cnt < 36
printf "@ begin= %d, end= %d, step= %d, i= %d\n", begin, end, step, i
end
cont
end

run -100 100 3 > /dev/null
quit
