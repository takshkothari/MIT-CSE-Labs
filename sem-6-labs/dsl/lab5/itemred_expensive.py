import fileinput
max_value = 0
old_key = None
for line in fileinput.input():
    data = line.strip().split("\t")
    if len(data) != 2:
        # Something has gone wrong. Skip this line.
        continue
    current_key, current_value = data
    # print(current_key, current_value)
    # Refresh for new keys (i.e. locations in the example context)
    if old_key and old_key != current_key:
        print(old_key,"\t", max_value)
        max_value = 0
    if float(current_value) > float(max_value):
        max_value = float(current_value)
    old_key = current_key
if old_key != None:
    print (old_key, "\t", max_value)