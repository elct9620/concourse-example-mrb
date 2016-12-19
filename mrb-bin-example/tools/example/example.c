#include "stdio.h"

#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/string.h"

int main(int argc, char** argv) {
  mrb_state* mrb = mrb_open();

  mrb_load_string(mrb, argv[1]);

  if(mrb->exc) {
    mrb_print_error(mrb);
  }

  mrb_close(mrb);
}
