#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([sht1x-java], [1.0], [jruiz@johnruiz.com])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AC_LIBTOOL_DLOPEN
AC_CONFIG_FILES([Makefile])
# AC_CONFIG_SRCDIR([Sht1xSensor.h])
# AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AX_JNI_INCLUDE_DIR
for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS
do
	CPPFLAGS="$CPPFLAGS -I$JNI_INCLUDE_DIR"
done

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
