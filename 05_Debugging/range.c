#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, begin, end, step = 0;
	switch(argc) {
	case 2:
		begin = 1;
		end = atoi(argv[1]);
		step = 1;
		break;
	case 3:
		begin = atoi(argv[1]);
		end = atoi(argv[2]);
		step = 1;
		break;
	case 4:
		begin = atoi(argv[1]);
		end = atoi(argv[2]);
		step = atoi (argv[3]);
		break;
	default:
		printf("-----range-----\n<int N> -- prints numbers from 0 to N-1\n <int N> <int M> -- prints numbers from N to M-1\n <int N> <int M> <int K> -- prints numbers from N to M with a step K");
		return 0;
	}
	for(i = begin; i < end; i += step){
		printf("%d\n", i);
	}
	return 0;
}
