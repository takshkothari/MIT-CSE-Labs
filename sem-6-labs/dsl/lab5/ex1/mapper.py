import sys
for line in sys.stdin: # input comes from STDIN (standard input)
    line = line.strip() # remove leading and trailing whitespace
    words = line.split() # split the line into words
    # increase counters
    for word in words:
    # write the results to STDOUT (standard output);
    # what we output here will be the input for the
    # Reduce step, i.e. the input for reducer.py #
    # tab-delimited; the trivial word count is 1
        print("%s\t\t%s" %(word, 1))