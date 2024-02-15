import sys
transactions_count = 0
age_total = 0
for line in sys.stdin:
    data = line.strip().split("\t")
    if len(data) != 2:
        # Something has gone wrong. Skip this line.
        continue
    age, target = data
    transactions_count += 1
    if age.isdigit():
        age_total += float(age)
print (transactions_count, "\t", age_total)