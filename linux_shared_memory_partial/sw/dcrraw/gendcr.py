#!/usr/bin/env python

print
print "unsigned long dcr_read(int dcrn)\n{"
print "\tswitch(dcrn){"

for dcrn in range(0,1024):
	print "\t\tcase %i:" % dcrn
	print "\t\t\t__asm__(\"mfdcr 3,%i\");" % dcrn
	print "\t\t\tbreak;"

print "\t}"
print "}"
print

print "void dcr_write(int dcrn, unsigned long value)\n{"
print "\tswitch(dcrn){"

for dcrn in range(0,1024):
	print "\t\tcase %i:" % dcrn
	print "\t\t\t__asm__(\"mtdcr %i,4\");" % dcrn
	print "\t\t\tbreak;"

print "\t}"
print "}"
print

