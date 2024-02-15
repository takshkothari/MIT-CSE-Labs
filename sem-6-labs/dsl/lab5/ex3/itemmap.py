#import string
import sys
for line in sys.stdin:
    data = line.strip().split(",")
    if len(data) == 14:
        age,sex,cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal,target = data
        print ("{0}\t{1}".format(age, target))