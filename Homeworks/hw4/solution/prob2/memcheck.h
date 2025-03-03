#ifndef CS100_MEMCHECK_H
#define CS100_MEMCHECK_H 1

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

struct Record {
  void *ptr;              // address of the allocated memory
  size_t size;            // size of the allocated memory
  int line_no;            // line number, at which a call to malloc or calloc happens
  const char *file_name;  // name of the file, in which the call to malloc or calloc happens
};

struct Record records[MAX_RECORDS];
static int index = 0;

void *recorded_malloc(size_t size, int line, const char *file) {
  void *ptr = malloc(size);
  if (ptr != NULL) {
    // YOUR CODE HERE
    struct Record record;
    record.ptr = ptr;
    record.size = size;
    record.line_no = line;
    record.file_name = file;
    records[index++] = record;
  }
  return ptr;
}

void *recorded_calloc(size_t cnt, size_t each_size, int line, const char *file) {
  void *ptr = calloc(cnt, each_size);
  if (ptr != NULL) {
    // YOUR CODE HERE
    struct Record record;
    record.ptr = ptr;
    record.size = cnt * each_size;
    record.line_no = line;
    record.file_name = file;
    records[index++] = record;
  }
  return ptr;
}

void recorded_free(void *ptr, int line, const char *file) {
  // YOUR CODE HERE
  if (ptr != NULL){
    int j;
    for (j = 0; j < index; j++){
      if (records[j].ptr == ptr){
        records[j].ptr = NULL;
        free(ptr);
        return;
      }
    }
    printf("Invalid free in file %s, line %d\n", file, line);
  }
}

void check_leak(void) __attribute__((destructor));

void check_leak(void) {
  // YOUR CODE HERE
  printf("Summary:\n");
  int allocations = 0;
  size_t bytes = 0;
  for (int j = 0; j < index; j++){
    if (records[j].ptr != NULL){
      printf("%ld bytes memory not freed (allocated in file %s, line %d)\n", \
      records[j].size, records[j].file_name, records[j].line_no);
      allocations++;
      bytes += records[j].size;
    }
  }
  if (allocations){
    printf("%d allocation records not freed (%ld bytes in total).\n", allocations, bytes);
  } else{
    printf("All allocations have been freed.\n");
  }
}

#define malloc(SIZE) recorded_malloc(SIZE, __LINE__, __FILE__)
#define calloc(CNT, EACH_SIZE) recorded_calloc(CNT, EACH_SIZE, __LINE__, __FILE__)
#define free(PTR) recorded_free(PTR, __LINE__, __FILE__)

#endif // CS100_MEMCHECK_H
