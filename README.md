Description:
============

This is an simple example of libcpuid usage. It's heavily based on the
libcpuid upstream example: https://libcpuid.sourceforge.net/documentation.html
Currently, only the '-l' option was added.


Requirements:
=============

- libcpuid-devel


Compilation:
============

$ make


Usage:
======

Give details of your CPU:

 ./libcpuid-test

Give list of all known CPUs from the vendor of your CPU:

 ./libcpuid-test -l


License:
========

BSD.
