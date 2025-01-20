# c-alculator - Simple calculator using C.

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

uninstall:
	@echo Removing executable from ${DESTDIR}${PREFIX}/bin...
	@rm -f ${DESTDIR}${PREFIX}/bin/c-alculator

.PHONY: all options clean dist install test uninstall
