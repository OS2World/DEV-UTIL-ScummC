#-------------------------------------------------------------------
# ScummC v0.2.0 Makefile for OS/2--XFree86/OS2v4.5--Gtk+-2.0
#-------------------------------------------------------------------
# Copyright (C) 2008  Frank Ambacher
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#-------------------------------------------------------------------
# Macros
#-------------------------------------------------------------------
CC     = gcc
CFLAGS = -o2 -Zmtd -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include \
-I/usr/include/atk-1.0 -I/usr/include/pango-1.0 -I/usr/X11R6/include/freetype2 \
-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include

LDFLAGS = -Zmtd -L/usr/X11R6/lib -lgtk-x11-2.0 -lfontconfig -lgdk-x11-2.0 \
-latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 \
-lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lintl


all     : rd.exe imgsplit.exe zpnn2bmp.exe imgremap.exe raw2voc.exe palcat.exe scc.exe char.exe sld.exe cost.exe midi.exe soun.exe boxedit.exe costview.exe scvm.exe

clean :
	@if exist *.o del *.o
	@if exist *.exe del *.exe


rd.exe : rd.o code.o decode.o read.o write.o scc_fd.o scc_util.o scc_cost.o
	$(CC) rd.o code.o decode.o read.o write.o scc_fd.o scc_util.o scc_cost.o

zpnn2bmp.exe : zpnn2bmp.o scc_fd.o scc_param.o decode.o scc_img.o scc_util.o
	$(CC) zpnn2bmp.o scc_fd.o scc_param.o decode.o scc_img.o scc_util.o

imgsplit.exe : imgsplit.o scc_fd.o scc_param.o scc_img.o scc_util.o
	$(CC) imgsplit.o scc_fd.o scc_param.o scc_img.o scc_util.o

imgremap.exe : imgremap.o scc_fd.o scc_param.o scc_img.o scc_util.o
	$(CC) imgremap.o scc_fd.o scc_param.o scc_img.o scc_util.o

raw2voc.exe  : raw2voc.o scc_fd.o scc_param.o scc_util.o
	$(CC) raw2voc.o scc_fd.o scc_param.o scc_util.o

palcat.exe   : palcat.o scc_img.o scc_fd.o scc_param.o scc_util.o
	$(CC) palcat.o scc_img.o scc_fd.o scc_param.o scc_util.o

scc.exe      : scc_parse.tab.o scc_util.o scc_ns.o scc_target.o scc_roobj.o scc_img.o scc_code.o \
            code.o write.o scc_lex.o scc_lexer.o scc_fd.o scc_param.o
	$(CC) -o scc.exe scc_parse.tab.o scc_util.o scc_ns.o scc_target.o scc_roobj.o scc_img.o scc_code.o \
             code.o write.o scc_lex.o scc_lexer.o scc_fd.o scc_param.o

sld.exe      : scc_ld.o scc_ns.o scc_target.o scc_code.o scc_fd.o scc_param.o scc_util.o
	$(CC) -o sld.exe scc_ld.o scc_ns.o scc_target.o scc_code.o scc_fd.o scc_param.o scc_util.o

cost.exe     : cost_parse.tab.o scc_fd.o scc_param.o scc_img.o scc_util.o scc_lex.o cost_lexer.o
	$(CC) -o cost.exe cost_parse.tab.o scc_fd.o scc_param.o scc_img.o scc_util.o scc_lex.o cost_lexer.o

char.exe     : char.o scc_fd.o scc_param.o scc_img.o scc_util.o scc_char.o
	$(CC) char.o scc_fd.o scc_param.o scc_img.o scc_util.o scc_char.o -L/usr/X11R6/lib -lfreetype

midi.exe     : midi.o scc_smf.o scc_fd.o scc_param.o scc_util.o
	$(CC) midi.o scc_smf.o scc_fd.o scc_param.o scc_util.o

soun.exe     : soun.o scc_fd.o scc_param.o scc_util.o
	$(CC) soun.o scc_fd.o scc_param.o scc_util.o

costview.exe : costview.o scc_fd.o decode.o read.o write.o scc_util.o scc_cost.o code.o scc_img.o scc_param.o
	$(CC) costview.o scc_fd.o decode.o read.o write.o scc_util.o scc_cost.o code.o scc_img.o scc_param.o $(LDFLAGS)

boxedit.exe  : boxedit.o read.o write.o scc_fd.o scc_cost.o scc_img.o scc_param.o scc_util.c scc_box.c
	$(CC) boxedit.o read.o write.o scc_fd.o scc_cost.o scc_img.o scc_param.o scc_util.c scc_box.c $(LDFLAGS)

scvm.exe     : scvm.o scvm_dbg.o scvm_res.o scvm_thread.o scvm_op.o scvm_view.o scvm_actor.o scc_fd.o \
             scc_util.o scc_param.o scc_cost.o scc_char.o scc_box.o decode.o
	$(CC) scvm.o scvm_dbg.o scvm_res.o scvm_thread.o scvm_op.o scvm_view.o scvm_actor.o scc_fd.o \
             scc_util.o scc_param.o scc_cost.o scc_char.o scc_box.o decode.o -L/usr/lib/sdl-1.2 -lsdl12
