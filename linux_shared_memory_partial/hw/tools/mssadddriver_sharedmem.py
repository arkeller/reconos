#!/usr/bin/python
#
# mssadddriver.py: add generic osif drivers to a mss file
#

import sys
import reconos.mhs_sharedmem


def exitUsage():
	sys.stderr.write("Usage: %s <mss_file> num_osifs\n" % sys.argv[0])
	sys.exit(1)
	
	
if __name__ == "__main__":
	
	if len(sys.argv) < 3: exitUsage()
		
	mss_orig = sys.argv[1]
	num_slots = int(sys.argv[2])
	
	mss_file = open(mss_orig,"r")
	
	while 1:
		line = mss_file.readline()
		if not line:
			break
		
		sys.stdout.write(line)
		
	for i in range(num_slots):
		s = """BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = osif_%d
END

""" % i
		sys.stdout.write(s)


