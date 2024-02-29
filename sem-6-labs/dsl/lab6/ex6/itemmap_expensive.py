import fileinput
for line in fileinput.input():
    data = line.strip().split(',')
    if len(data) == 8:
        sr,obsdate,state,country,lu,conf,death,rec = data
        print ("{0}\t{1}".format(country, conf))


        #SNo,ObservationDate,Province/State,Country/Region,Last Update,Confirmed,Deaths,Recovered
