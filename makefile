#!/usr/bin/env make

.PHONY: all clean

ARCH ?= x86
PLATFORM ?= intel
FORMAT ?= elf_i386
ROOTDIR := $(realpath .)

export ARCH
export PLATFORM
export ROOTDIR

ISODIR := iso

TARGET := kernel.bin
IMAGE := jatos-$(PLATFORM)-$(ARCH).iso

LDFLAGS := -m $(FORMAT) -T arch/$(ARCH)/link.ld

LIBS := \
	libc/libc.a \
	arch/$(ARCH)/libarch.a \
	platform/$(PLATFORM)/libplatform.a

all: $(TARGET)

	mkdir -p $(ISODIR)
	
	cp -r boot $(ISODIR)/boot
	cp $(TARGET) $(ISODIR)/boot
	
	grub-mkrescue --output=$(IMAGE) $(ISODIR)
	rm -rf $(ISODIR)

clean:

	$(MAKE) -C libc clean
	$(MAKE) -C arch/$(ARCH) clean
	$(MAKE) -C platform/$(PLATFORM) clean

	rm -f $(TARGET)
	rm -f $(IMAGE)

$(TARGET): $(LIBS)

	$(LD) $(LDFLAGS) --start-group $^ --end-group -o $@

$(LIBS):

	$(MAKE) -C libc all
	$(MAKE) -C arch/$(ARCH) all
	$(MAKE) -C platform/$(PLATFORM) all
