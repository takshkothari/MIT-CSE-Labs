#!/usr/bin/env python
# A basic mapper function/program that
# takes whatever is passed on the input and
# outputs tuples of all the words formatted
# as (word, 1)
from __future__ import print_function
import sys
# input comes from STDIN (standard input)
for line in sys.stdin:
    # print(line.strip().split())
    word, count = line.strip().split(',')
    count = int(count)
    print( '%d,%s' % (count, word) )