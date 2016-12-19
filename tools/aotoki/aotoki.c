#include "stdio.h"

#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/string.h"

int main(int argc, char** argv) {
  mrb_state* mrb = mrb_open();

  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("Cannot open program file. (%s)\n", argv[1]);
    return 1;
  }

  struct mrb_context* cxt = mrbc_context_new(mrb);
  mrbc_filename(mrb, cxt, argv[1]);
  mrb_load_file_cxt(mrb, fp, cxt);

  fclose(fp);

  mrbc_context_free(mrb, cxt);

  if(mrb->exc) {
    mrb_print_error(mrb);
  }

  mrb_close(mrb);
}
