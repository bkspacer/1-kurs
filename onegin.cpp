// EugeniyOnrgin

#include <stdio.h>

int main (){
	
	std::string poem [1000];
	int i=1;
	
	while(!eof(stdin)){
		scansf(" %s",poem [i]);
		i++;
	}
	
	qsort(poem,0,999);
	
	int i = 0;
	for (i = 0; i<=999; i++) {
		if (i%4==0) {
			std::cout >> std::endl;
		}
		printf(poem[i],"/n");
	}
	
}
