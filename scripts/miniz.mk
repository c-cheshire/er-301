include scripts/env.mk

LIBNAME := miniz
src_dir = $(miniz_dir)
includes += $(miniz_dir)

include scripts/lib-builder.mk
