#
#  ScummC Makefile
#  Copyright (C) 2006  Alban Bedel
# 
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#


SRCS= common.scc road.scc

host=$(shell uname -n | cut -d . -f 1)

SRCDIR?=../..

include $(SRCDIR)/config.$(host).mak

EXP_DIR=$(SRCDIR)/examples/road7

REF_FILE=$(EXP_DIR)/road.md5

BIN_PATH=$(SRCDIR)/$(BUILDROOT)/$(TARGET)

SCC=$(BIN_PATH)/scc
SLD=$(BIN_PATH)/sld
COST=$(BIN_PATH)/cost
CHAR=$(BIN_PATH)/char

SCC_FLAGS= -V 7 -I $(SRCDIR) -I $(EXP_DIR) -R $(EXP_DIR)

OBJS=$(SRCS:%.scc=%.roobj)
EXP_SRCS=$(SRCS:%=$(EXP_DIR)/%)


all: scummc7.000 scummc7.001 scummc7.sou


%.cost: $(EXP_DIR)/%.scost $(COST)
	$(COST) -o $@ -akos -I $(EXP_DIR) $<

%.char: $(EXP_DIR)/%.bmp $(CHAR)
	$(CHAR) -ochar $@ -ibmp $<

%.roobj: $(EXP_DIR)/%.scc $(SCC)
	$(SCC) -o $@ $(SCC_FLAGS) $<

scummc7.000: $(OBJS)
	$(SLD) -vv $^

scummc7.001 scummc7.sou: scummc7.000 ;

clean:
	rm -f road.dep scummc7.0?? *.char scummc7.sou *.roobj *.cost

distclean: clean


road.dep: $(EXP_SRCS)
	$(SCC) -d -o $@ $(SCC_FLAGS) $^

-include road.dep

### Regression testing

## Update the reference hash.
test-ref: scummc.000 scummc.001 scummc.sou
	@for f in $+ ; do printf "%s: " $$f ; $(MD5SUM) < $$f | cut -d ' ' -f 1 ; done > $(REF_FILE)
	@echo "Reference hash updated."

test: scummc.000 scummc.001 scummc.sou
	@[ -f $(REF_FILE) ] || ( echo "No reference hash available" ; false )
	@for f in $+ ; do \
           printf "%s: " $$f ; \
           $(MD5SUM) < $$f | cut -d ' ' -f 1 ; \
        done | diff -u $(REF_FILE) -

.PHONY: clean distclean test-ref test
