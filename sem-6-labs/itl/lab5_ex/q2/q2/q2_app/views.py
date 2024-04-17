from django.shortcuts import render
from ntpath import join
import datetime

# Create your views here.
def index(request):
	return render(request, 'basic.html')

def employee(request):

    join_date = request.POST['date']

    current_year = datetime.today().year
    joining_year = datetime.strptime(join_date, '%d/%m/%Y').year

    print("\n\n", current_year, joining_year, "\n\n")

    if (current_year - joining_year) > 5:

        return render(request, "basic.html", {"result": "  Yes"})
    else:
        return render(request, "basic.html", {"result": "  NO"})