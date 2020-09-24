#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int thread_count = 2;
long fibo_result = 0, n = 30;

/**
 * Recursive Fibonacci function
*/
long fibo(long n) {
  if (n < 2)
    return 1;
  else return fibo(n-1) + fibo(n-2);
}

void *thread_fibo(void *rank) {
  long my_rank = (long) rank;
  long my_n;
  if (my_rank % thread_count == 0)
    my_n = n - 2;
  else
    my_n = n - 1;

  long my_fibo_result = fibo(my_n);

  fibo_result += my_fibo_result;

  return NULL;
}                                          
  
int main(void) {
  long thread, recursive_fibo;
  struct timeval tv;
  double start_t, end_t, time_delta1, time_delta2;
  pthread_t *thread_handles;

  thread_handles = malloc(thread_count * sizeof(pthread_t));

  gettimeofday(&tv, NULL);
  start_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // start time in miliseconds
  for (thread = 0; thread < thread_count; thread++)
    pthread_create(&thread_handles[thread], NULL, thread_fibo, (void *) thread);

  gettimeofday(&tv,NULL); 
  end_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // end time in miliseconds
  time_delta1 = end_t - start_t;
  
  for (thread = 0; thread < thread_count; thread++)
    pthread_join(thread_handles[thread], NULL);

  printf("\n parallel fibonacci of %ld = %ld - execution time: %f ms", n, fibo_result, time_delta1);

  gettimeofday(&tv, NULL);
  start_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // start time in miliseconds
  
  recursive_fibo = fibo(n);

  gettimeofday(&tv,NULL); 
  end_t = (double) (tv.tv_sec*1000.0) + (double) (tv.tv_usec / 1000.0); // end time in miliseconds
  time_delta2 = end_t - start_t;

  printf("\n recursive fibonacci of %ld = %ld - execution time: %f ms", n, fibo(n), time_delta2);

  free(thread_handles);
  return 0;
}
