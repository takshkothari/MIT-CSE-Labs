# MapReduce program to find frequent words
#!/usr/bin/env python
# A basic mapper function/program that
# takes whatever is passed on the input and
# outputs tuples of all the words formatted
# as (word, 1)
from __future__ import print_function
import sys
import pandas as pd
df = pd.read_excel('german.xlsx')
for _, row in df.iterrows():
    line = ", ".join([str(value) for value in row.values])
    words = line.split(',')
    for word in words:
        print( '%s\t%d' % (word, 1) )



'''
# input comes from STDIN (standard input)
for line in sys.stdin:
    # create tuples of all words in line
    L = [ (word.strip().lower(), 1 ) for word in line.strip().split(',') ]
    # increase counters
    for word, n in L:
        # write the results to STDOUT (standard output);
        # what we output here will be the input for the
        # Reduce step, i.e. the input for reducer.py
        #
        # tab-delimited; the trivial word count is 1
        print( '%s,%d' % (word, n) )
        '''