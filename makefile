# MIT License
#
# Copyright (c) 2025 Gabriel Santos
# Copyright (c) 2016 Christopher McFee <cmcfee@cryptolab.net>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# c-alculator - Simple calculator using C.

include config.mk

SRC = c-alculator.c
OBJ = ${SRC:.c=.o}

all: options c-alculator

options:
	@echo c-alculator build options:
	@echo "CFLAGS = ${CFLAGS}"
	@echo "CC     = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

c-alculator: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${CFLAGS}

clean:
	@echo Cleaning...
	@rm -f c-alculator ${OBJ} c-alculator-${VERSION}.tar.gz

dist: clean
	@echo Creating dist tarball...
	@mkdir -p c-alculator-${VERSION}
	@cp -R LICENSE makefile README.org config.mk ${SRC} c-alculator-${VERSION}
	@tar -cf c-alculator-${VERSION}.tar c-alculator-${VERSION}
	@gzip c-alculator-${VERSION}.tar
	@rm -rf c-alculator-${VERSION}

install: all
	@echo Installing executable to ${DESTDIR}${PREFIX}/bin...
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f c-alculator ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/c-alculator
	@chmod u+s ${DESTDIR}${PREFIX}/bin/c-alculator

test: all
	@echo Running executable for testing...
	@mkdir -p ${PWD}/test
	@mv c-alculator ${PWD}/test
	@chmod 755 ${PWD}/test/c-alculator
	@chmod u+s ${PWD}/test/c-alculator
	@${PWD}/test/c-alculator
	@echo Cleaning up after test...
	@rm -rf ${PWD}/test

uninstall:
	@echo Removing executable from ${DESTDIR}${PREFIX}/bin...
	@rm -f ${DESTDIR}${PREFIX}/bin/c-alculator

.PHONY: all options clean dist install test uninstall
