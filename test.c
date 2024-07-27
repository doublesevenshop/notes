#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int x = 0, y = 0;

pthread_t ptid1, ptid2;
void *pth1_main(void *arg);
void *pth2_main(void* arg);

int main() {
	if(pthread_create(&ptid1, NULL, pth1_main, (void*)0) != 0) {
		printf("pthread_create ptid1 failed!\n");
		return -1;
	}
	if(pthread_create(&ptid2, NULL, pth2_main, (void*)0) != 0) {
		printf("pthread_create ptid2 failed!\n");
		return -1;
	}

	printf("11111111111111\n");

	pthread_join(ptid1, NULL);

	printf("22222222222222\n");
	pthread_join(ptid2, NULL);

	printf("33333333333333\n");

	return 0;
}

void *pth1_main(void* arg) {
	for(x = 0; x < 100; x++) {
		printf("x=%d\n", x);
		sleep(1);
	}
	pthread_exit(NULL);
}

void *pth2_main(void* arg) {
	for(y = 0; y < 100; y++) {
		printf("y=%d\n", y);
		sleep(1);
	}
	pthread_exit(NULL);