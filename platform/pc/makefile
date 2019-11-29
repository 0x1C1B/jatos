#!/usr/bin/env make

.PHONY: all clean

CC := gcc
AR := ar
AS := nasm

SRCDIR := src
OBJDIR := obj

TARGET := libplatform.a

INCLUDE := \
	-I '$(ROOTDIR)/include/libc' \
	-I '$(ROOTDIR)/include/platform/$(PLATFORM)'

CFLAGS := -m32 -Wall -O -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin
ASFLAGS := -f elf
ARFLAGS := -rcs

SRCS := $(shell find $(SRCDIR) -name '*.asm') $(shell find $(SRCDIR) -name '*.c')
OBJS := $(subst $(SRCDIR), $(OBJDIR), $(patsubst %.c, %.o, $(patsubst %.asm, %.o, $(SRCS))))

all: $(TARGET)

$(TARGET): $(OBJS)

	$(AR) $(ARFLAGS) $@ $^
	
$(OBJDIR)/%.o: $(SRCDIR)/%.asm

	mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c

	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:

	rm -rf $(OBJDIR)
	rm -f $(TARGET)
